#include <iostream>
using namespace std;
/*4. Realice una función que dado un vector dinámico de enteros, remueva el 
elemento que se encuentra en una posición pasada por parámetro. Si la posición es 
mayor a la cantidad de elementos, la función no debe remover ningún elemento.
*/

void removerElemento(int*& vec, int& tam, int posicion) {
    if (posicion < 0 || posicion >= tam) {
        return;
    }
    int* nuevoVec = new int[tam - 1];
    for (int i = 0, j = 0; i < tam; i++) {
        if (i != posicion) {
            nuevoVec[j++] = vec[i];
        }
    }
    delete[] vec;
    vec = nuevoVec;
    tam--;
}

int main() {
    
    return 0;
}