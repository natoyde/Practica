#include <iostream>
#include <cstring>
using namespace std;
/*3. Realice una clase Cadena que permita representar una cadena cstring. La cadena debe
permitir:
a) Saber cuantos caracteres tiene la cadena
b) Agregar un carácter al final
c) Agregar un carácter al principio
d) Remover la primera ocurrencia de un carácter pasado por parámetro.
e) Retornar una cadena en mayúscula.*/

class Cadena {
private:
    char* datos;   // puntero a la cadena (cstring)
    int longitud;  // cantidad de caracteres

public:
    // Constructor
    Cadena(const char* str);
    int getlongitud(){
        return longitud;
    }
    char* getdatos(){
        return datos;
    }
    // a) Saber cuántos caracteres tiene
    int cantidadCaracteres() const;

    // b) Agregar un carácter al final
    void agregarAlFinal(char c);

    // c) Agregar un carácter al principio
    void agregarAlInicio(char c);

    // d) Remover la primera ocurrencia de un carácter
    void removerCaracter(char c);

    // e) Retornar una cadena en mayúscula
    Cadena aMayuscula() const;
    void mostrar() const;
};

Cadena::Cadena(const char* str) {
    if (str == nullptr) {
        longitud = 0;
        datos = new char[1];
        datos[0] = '\0';
    } else {
        longitud = strlen(str);
        datos = new char[longitud + 1];
        strcpy(datos, str);
    }
}


int Cadena::cantidadCaracteres() const {
    return longitud;
}

void Cadena :: agregarAlFinal(char c){
    char* nuevo = new char[longitud + 2]; // +1 char + '\0'

    strcpy(nuevo, datos);
    nuevo[longitud] = c;
    nuevo[longitud + 1] = '\0';

    delete[] datos;
    datos = nuevo;
    longitud++; 
}
void Cadena :: agregarAlInicio(char c){
    char* nuevo = new char[longitud + 2];

    nuevo[0] = c;
    strcpy(nuevo + 1, datos);

    delete[] datos;
    datos = nuevo;
    longitud++;
}

void Cadena :: removerCaracter(char c){
    int pos = -1;

    // buscar posición
    for (int i = 0; i < longitud; i++) {
        if (datos[i] == c) {
            pos = i;
            break;
        }
    }

    if (pos == -1) return; // no encontrado

    char* nuevo = new char[longitud]; // uno menos

    int j = 0;
    for (int i = 0; i < longitud; i++) {
        if (i != pos) {
            nuevo[j++] = datos[i];
        }
    }

    nuevo[j] = '\0';

    delete[] datos;
    datos = nuevo;
    longitud--;
}
Cadena Cadena::aMayuscula() const {
    Cadena nueva(datos);

    for (int i = 0; i < nueva.longitud; i++) {
        nueva.datos[i] = toupper(nueva.datos[i]);
    }

    return nueva;
}

void Cadena::mostrar() const {
    cout << datos << endl;
}
int main() {
    Cadena c1("hola");
    Cadena c2("hola");
    Cadena c3("hola");
    Cadena c4("hola");
   
    c1.mostrar();
    
    c2.agregarAlFinal('!');
    c2.mostrar();

    c3.agregarAlInicio('#');
    c3.mostrar();

    c4.removerCaracter('o');
    c4.mostrar();

    Cadena c5=c1.aMayuscula();
    c5.mostrar();

    return 0;
}