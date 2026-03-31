#include <iostream>
using namespace std;

/*8. Realice una función que dado un vector dinámico de enteros, retorne un vector con el
doble de elementos y los nuevos elementos deben ser una copia de los anteriores*/   

void duplicarVector(int* &vec, int &tam) {
    int* nuevoVec = new int[tam * 2];

    for (int i = 0; i < tam; i++) {
        nuevoVec[i] = vec[i];
        nuevoVec[i + tam] = vec[i];
    }

    delete[] vec; // liberar memoria vieja
    vec = nuevoVec;
    tam = tam * 2;
}

int main() {
    
    return 0;
}