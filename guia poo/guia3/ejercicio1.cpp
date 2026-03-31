#include <iostream>
using namespace std;
/*1. Realice una función que dado un vector dinámico de enteros, agregue un nuevo valor
pasado por parámetro en la ultima posición.*/

void agregarValor(int*& vec, int& tam, int valor) {
    int* nuevoVec = new int[tam + 1];
    for (int i = 0; i < tam; i++) {
        nuevoVec[i] = vec[i];
    }
    nuevoVec[tam] = valor;
    delete[] vec;
    vec = nuevoVec;
    tam++;
}
int main() {
    
    return 0;
}