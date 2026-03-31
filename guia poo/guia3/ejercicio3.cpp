#include <iostream>
using namespace std;
/*3. Realice una función que dado un vector dinámico de enteros, agregue un nuevo valor
pasado por parámetro en una posición pasada por parámetros.*/
void agregarvalorposicion(int*& vec, int& tam, int valor, int pos){
    int* nuevoVec = new int[tam + 1];
    for (int i = 0; i < tam+1; i++) {
        if (i==pos-1){
            nuevoVec[i]=valor;
            for (int j = i; j < tam+1; j++){
                nuevoVec[j+1]= vec[j];
            }
            break;
        }
        nuevoVec[i]= vec[i];
    }
    delete[] vec;
    vec = nuevoVec;
    tam++;
}


int main() {
    
    return 0;
}