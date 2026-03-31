#include <iostream>
using namespace std;
/*2. Realice una función que dado un vector dinámico de enteros, agregue un nuevo valor 
pasado por parámetro en la primera posición.*/

void agregarValorPrimeraPosicion(int*& vec, int& tam, int valor) {
    int* nuevoVec = new int[tam + 1];
    nuevoVec[0] = valor;
    for (int i = 0; i < tam; i++) {
        nuevoVec[i + 1] = vec[i];
    }
    delete[] vec;
    vec = nuevoVec;
    tam++;
}
int main() {
    
    return 0;
}