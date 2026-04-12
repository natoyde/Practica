#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <sstream>
#include <cstring>
using namespace std;

// ─── STRUCTS PARA ARCHIVOS BINARIOS ───────────────────────────────────────────

struct strusuario {
    char nombre[200];
    int cantEscrito;
};

// ─── CLASE MENSAJE ────────────────────────────────────────────────────────────

class Mensaje {
    private:
        string usuario;
        string contenido;
        bool esReaccion;
        vector<Mensaje*> respuestas;
    public:
        Mensaje(string usuario, string contenido, bool esReaccion = false);
        
        string getusuario()    { return usuario; }
        string getcontenido()  { return contenido; }
        bool getesReaccion()   { return esReaccion; }
        
        void agregarRespuesta(Mensaje* m) {
            respuestas.push_back(m);
        }

        vector<Mensaje*>& getRespuestas() {
            return respuestas;
        }

        // Cantidad de hilos anidados totales
        int cantHilos() {
            int total = respuestas.size();
            for (int i = 0; i < respuestas.size(); i++)
                total += respuestas[i]->cantHilos();
            return total;
        }

        ~Mensaje() {
            for (int i = 0; i < respuestas.size(); i++)
                delete respuestas[i];
        }
};

Mensaje::Mensaje(string usuario, string contenido, bool esReaccion) {
    this->usuario    = usuario;
    this->contenido  = contenido;
    this->esReaccion = esReaccion;
}

// ─── CLASE CHAT ───────────────────────────────────────────────────────────────

class Chat {
    private:
        vector<Mensaje*> mensajesRaiz;

        // Detecta si el contenido es una reacción (emoji no-ASCII)
        bool detectarReaccion(const string& contenido) {
            if (contenido.empty()) return false;
            for (unsigned char c : contenido) {
                if (c < 128 && c != ' ') return false;
            }
            return true;
        }

        // Cuenta hilos por usuario de forma recursiva
        void contarHilosPorUsuario(Mensaje* m, map<string, int>& conteo) {
            conteo[m->getusuario()] += m->cantHilos();
            for (int i = 0; i < m->getRespuestas().size(); i++)
                contarHilosPorUsuario(m->getRespuestas()[i], conteo);
        }

        // Cuenta mensajes escritos por usuario (excluye reacciones)
        void contarMensajesPorUsuario(Mensaje* m, map<string, int>& conteo) {
            if (!m->getesReaccion())
                conteo[m->getusuario()]++;
            for (int i = 0; i < m->getRespuestas().size(); i++)
                contarMensajesPorUsuario(m->getRespuestas()[i], conteo);
        }

    public:
        Chat();
        ~Chat();
        void leerarch(const string& nombreArchivo);
        void mensajesConMasHilos();
        string usuarioConMasHilos();
        map<string, int> vecesQueEscribio();
        void guardarBinario(const string& nombreArchivo);
};

Chat::Chat() {}

Chat::~Chat() {
    for (int i = 0; i < mensajesRaiz.size(); i++)
        delete mensajesRaiz[i];
}

// ─── (25) LEER ARCHIVO DE TEXTO Y CREAR OBJETOS ───────────────────────────────

void Chat::leerarch(const string& nombreArchivo) {
    ifstream archivo;
    archivo.open(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir: " << nombreArchivo << endl;
        return;
    }

    // pila[i] = último mensaje insertado en nivel i+1
    vector<Mensaje*> pila;
    string linea;

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        // Tokenizar por '.'
        vector<string> tokens;
        stringstream ss(linea);
        string tok;
        while (getline(ss, tok, '.'))
            tokens.push_back(tok);

        // Separar prefijo numérico del usuario y contenido
        vector<int> niveles;
        int idxUsuario = -1;
        for (int i = 0; i < tokens.size(); i++) {
            bool esNum = !tokens[i].empty() &&
                         all_of(tokens[i].begin(), tokens[i].end(), ::isdigit);
            if (esNum) {
                niveles.push_back(stoi(tokens[i]));
            } else {
                idxUsuario = i;
                break;
            }
        }
        if (idxUsuario == -1 || niveles.empty()) continue;

        string usuario = tokens[idxUsuario];

        // Reconstruir contenido uniendo tokens restantes
        string contenido = "";
        for (int i = idxUsuario + 1; i < tokens.size(); i++) {
            if (!contenido.empty()) contenido += ".";
            contenido += tokens[i];
        }
        if (!contenido.empty() && contenido[0] == ' ')
            contenido = contenido.substr(1);

        int nivel = niveles.size(); // nivel 1 = raíz
        bool esReacc = detectarReaccion(contenido);
        Mensaje* nuevo = new Mensaje(usuario, contenido, esReacc);

        if (nivel == 1) {
            mensajesRaiz.push_back(nuevo);
            pila.clear();
            pila.push_back(nuevo);
        } else {
            if ((int)pila.size() >= nivel - 1) {
                pila.resize(nivel - 1);
                pila.back()->agregarRespuesta(nuevo);
                pila.push_back(nuevo);
            }
        }
    }
    archivo.close();
}

// ─── (30) MÉTODOS STL ─────────────────────────────────────────────────────────

// Obtener línea(s) con mayor cantidad de hilos
void Chat::mensajesConMasHilos() {
    if (mensajesRaiz.empty()) return;

    vector<Mensaje*> ordenados = mensajesRaiz;
    sort(ordenados.begin(), ordenados.end(),
        [](Mensaje* a, Mensaje* b) {
            return a->cantHilos() > b->cantHilos();
        }
    );

    int mayor = ordenados[0]->cantHilos();
    for (int i = 0; i < ordenados.size(); i++) {
        if (ordenados[i]->cantHilos() == mayor)
            cout << ordenados[i]->getusuario() << ": "
                 << ordenados[i]->getcontenido()
                 << " (" << mayor << " hilos)" << endl;
    }
}

// Obtener el usuario que generó mayor cantidad de hilos
string Chat::usuarioConMasHilos() {
    map<string, int> conteo;
    for (int i = 0; i < mensajesRaiz.size(); i++)
        contarHilosPorUsuario(mensajesRaiz[i], conteo);

    auto it = max_element(conteo.begin(), conteo.end(),
        [](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second < b.second;
        }
    );
    return (it != conteo.end()) ? it->first : "";
}

// Obtener usuario y veces que escribió usando accumulate
map<string, int> Chat::vecesQueEscribio() {
    map<string, int> conteo;
    for (int i = 0; i < mensajesRaiz.size(); i++)
        contarMensajesPorUsuario(mensajesRaiz[i], conteo);
    return conteo;
}

// ─── (20) GUARDAR EN ARCHIVO BINARIO ──────────────────────────────────────────

void Chat::guardarBinario(const string& nombreArchivo) {
    map<string, int> conteo = vecesQueEscribio();

    ofstream bin;
    bin.open(nombreArchivo, ios::binary);
    if (!bin.is_open()) {
        cout << "Error al crear archivo binario." << endl;
        return;
    }

    strusuario aux;
    for (auto it = conteo.begin(); it != conteo.end(); it++) {
        memset(aux.nombre, 0, sizeof(aux.nombre));
        strncpy(aux.nombre, it->first.c_str(), 199);
        aux.cantEscrito = it->second;
        bin.write((char*)&aux, sizeof(strusuario));
    }
    bin.close();
}

int main() {

    return 0;
}