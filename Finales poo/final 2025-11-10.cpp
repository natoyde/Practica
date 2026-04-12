#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <cstring>
using namespace std;

// ─── STRUCTS PARA ARCHIVOS BINARIOS ───────────────────────────────────────────

struct strcliente {
    int dni;
    char nombre[200];
};

struct strreserva {
    int dni_c;
    char tipo[10];
    int duracion;
    double costo;
};

// ─── CLASE RESERVA (base) ─────────────────────────────────────────────────────

class Reserva {
    protected:
        int dni_c;
        string tipo;
        int duracion;
    public:
        Reserva(int dni_c, string tipo, int duracion);
        int getdni_c()       { return dni_c; }
        string gettipo()     { return tipo; }
        int getduracion()    { return duracion; }
        virtual double getcosto() = 0;  // cada tipo calcula su costo
};

Reserva::Reserva(int dni_c, string tipo, int duracion) {
    this->dni_c    = dni_c;
    this->tipo     = tipo;
    this->duracion = duracion;
}

// ─── RESERVA ESTÁNDAR ─────────────────────────────────────────────────────────

class ReservaEstandar : public Reserva {
    public:
        ReservaEstandar(int dni_c, int duracion)
            : Reserva(dni_c, "Estandar", duracion) {}

        double getcosto() {
            return duracion * 15000.0;
        }
};

// ─── RESERVA PREMIUM ──────────────────────────────────────────────────────────

class ReservaPremium : public Reserva {
    public:
        ReservaPremium(int dni_c, int duracion)
            : Reserva(dni_c, "Premium", duracion) {}

        double getcosto() {
            return duracion * 30000.0 * 1.10;
        }
};

// ─── RESERVA MIXTA ────────────────────────────────────────────────────────────

class ReservaMixta : public Reserva {
    private:
        int nochesEstandar;
        int nochesPremium;
    public:
        ReservaMixta(int dni_c, int nochesEstandar, int nochesPremium)
            : Reserva(dni_c, "Mixta", nochesEstandar + nochesPremium),
              nochesEstandar(nochesEstandar), nochesPremium(nochesPremium) {}

        double getcosto() {
            return (nochesEstandar * 15000.0) + (nochesPremium * 30000.0 * 1.10);
        }
};

// ─── CLASE CLIENTE ────────────────────────────────────────────────────────────

class Cliente {
    private:
        int dni;
        string nombre;
        vector<Reserva*> vec_reserva;
    public:
        Cliente(int dni, string nombre);
        int getdni()         { return dni; }
        string getnombre()   { return nombre; }
        vector<Reserva*>& getreservas() { return vec_reserva; }

        void agregarreserva(Reserva* r) {
            vec_reserva.push_back(r);
        }
};

Cliente::Cliente(int dni, string nombre) {
    this->dni    = dni;
    this->nombre = nombre;
}

// ─── CLASE GESTOR ─────────────────────────────────────────────────────────────

class Gestor {
    private:
        vector<Cliente> vec_cliente;

        // Busca cliente por dni, retorna puntero o nullptr
        Cliente* buscarCliente(int dni) {
            for (int i = 0; i < vec_cliente.size(); i++)
                if (vec_cliente[i].getdni() == dni)
                    return &vec_cliente[i];
            return nullptr;
        }

    public:
        Gestor();
        void agregarCliente(int dni, string nombre);
        void agregarReserva(Reserva* r);

        // (20) Guardar reservas en archivo de texto
        void guardarTexto(const string& nombreArchivo);

        // (30) STL
        void cincoPorMasEconomicas();
        void reservasMasDuracion();
        void reservasBajoCosto(double maximo);

        // (4 - 30) Guardar en binario
        void guardarBinario(const string& archClientes, const string& archReservas);
};

Gestor::Gestor() {}

void Gestor::agregarCliente(int dni, string nombre) {
    vec_cliente.push_back(Cliente(dni, nombre));
}

void Gestor::agregarReserva(Reserva* r) {
    Cliente* c = buscarCliente(r->getdni_c());
    if (c != nullptr)
        c->agregarreserva(r);
}

// ─── (20) GUARDAR EN ARCHIVO DE TEXTO ─────────────────────────────────────────
// Formato: nombre cliente ... tipo reserva ... duracion total ... costo final

void Gestor::guardarTexto(const string& nombreArchivo) {
    ofstream archivo;
    archivo.open(nombreArchivo);

    for (int i = 0; i < vec_cliente.size(); i++) {
        vector<Reserva*>& reservas = vec_cliente[i].getreservas();
        for (int j = 0; j < reservas.size(); j++) {
            archivo << vec_cliente[i].getnombre()   << " ... "
                    << reservas[j]->gettipo()        << " ... "
                    << reservas[j]->getduracion()    << " ... "
                    << reservas[j]->getcosto()        << endl;
        }
    }
    archivo.close();
}

// ─── (30) MÉTODOS STL ─────────────────────────────────────────────────────────

// Arma un vector plano con todas las reservas (con nombre del cliente)
// útil para los tres métodos siguientes
vector<pair<string, Reserva*>> Gestor_todasReservas(vector<Cliente>& vec_cliente) {
    vector<pair<string, Reserva*>> todas;
    for (int i = 0; i < vec_cliente.size(); i++) {
        vector<Reserva*>& reservas = vec_cliente[i].getreservas();
        for (int j = 0; j < reservas.size(); j++)
            todas.push_back(make_pair(vec_cliente[i].getnombre(), reservas[j]));
    }
    return todas;
}

// Determinar las 5 reservas más económicas
void Gestor::cincoPorMasEconomicas() {
    vector<pair<string, Reserva*>> todas = Gestor_todasReservas(vec_cliente);

    sort(todas.begin(), todas.end(),
        [](pair<string, Reserva*> a, pair<string, Reserva*> b) {
            return a.second->getcosto() < b.second->getcosto();
        }
    );

    int limite = min((int)todas.size(), 5);
    cout << "=== 5 reservas mas economicas ===" << endl;
    for (int i = 0; i < limite; i++)
        cout << todas[i].first << " | " << todas[i].second->gettipo()
             << " | $" << todas[i].second->getcosto() << endl;
}

// Mostrar la/s reserva/s con más duración
void Gestor::reservasMasDuracion() {
    vector<pair<string, Reserva*>> todas = Gestor_todasReservas(vec_cliente);
    if (todas.empty()) return;

    sort(todas.begin(), todas.end(),
        [](pair<string, Reserva*> a, pair<string, Reserva*> b) {
            return a.second->getduracion() > b.second->getduracion();
        }
    );

    int mayor = todas[0].second->getduracion();
    cout << "=== Reservas con mayor duracion ===" << endl;
    for (int i = 0; i < todas.size(); i++) {
        if (todas[i].second->getduracion() == mayor)
            cout << todas[i].first << " | " << todas[i].second->gettipo()
                 << " | " << mayor << " noches" << endl;
    }
}

// Mostrar reservas cuyo costo no supere un máximo ingresado por el usuario
void Gestor::reservasBajoCosto(double maximo) {
    vector<pair<string, Reserva*>> todas = Gestor_todasReservas(vec_cliente);

    vector<pair<string, Reserva*>> filtradas;
    copy_if(todas.begin(), todas.end(), back_inserter(filtradas),
        [maximo](pair<string, Reserva*> p) {
            return p.second->getcosto() <= maximo;
        }
    );

    cout << "=== Reservas con costo <= $" << maximo << " ===" << endl;
    for (int i = 0; i < filtradas.size(); i++)
        cout << filtradas[i].first << " | " << filtradas[i].second->gettipo()
             << " | $" << filtradas[i].second->getcosto() << endl;
}

// ─── (4-30) GUARDAR EN ARCHIVOS BINARIOS ──────────────────────────────────────

void Gestor::guardarBinario(const string& archClientes, const string& archReservas) {
    // Archivo de clientes
    ofstream binC;
    binC.open(archClientes, ios::binary);
    strcliente auxC;
    for (int i = 0; i < vec_cliente.size(); i++) {
        auxC.dni = vec_cliente[i].getdni();
        memset(auxC.nombre, 0, sizeof(auxC.nombre));
        strncpy(auxC.nombre, vec_cliente[i].getnombre().c_str(), 199);
        binC.write((char*)&auxC, sizeof(strcliente));
    }
    binC.close();

    // Archivo de reservas
    ofstream binR;
    binR.open(archReservas, ios::binary);
    strreserva auxR;
    for (int i = 0; i < vec_cliente.size(); i++) {
        vector<Reserva*>& reservas = vec_cliente[i].getreservas();
        for (int j = 0; j < reservas.size(); j++) {
            auxR.dni_c    = reservas[j]->getdni_c();
            auxR.duracion = reservas[j]->getduracion();
            auxR.costo    = reservas[j]->getcosto();
            memset(auxR.tipo, 0, sizeof(auxR.tipo));
            strncpy(auxR.tipo, reservas[j]->gettipo().c_str(), 9);
            binR.write((char*)&auxR, sizeof(strreserva));
        }
    }
    binR.close();
}

// ─── MAIN ─────────────────────────────────────────────────────────────────────

int main() {

    return 0;
}