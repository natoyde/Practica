#include <iostream>
using namespace std;
/*5. Realice una función que dado un vector dinámico de enteros, remueva la primera
coincidencia de un elemento pasado por parámetro*/

void removerElemento(int* &vector, int &tam, int elemento) {
    for (int i = 0; i < tam; i++) {
        if (vector[i] == elemento) {
            for (int j = i; j < tam - 1; j++) {
                vector[j] = vector[j + 1];
            }
            tam--;
            break;
        }
    }
}

int main() {
    
    return 0;
}