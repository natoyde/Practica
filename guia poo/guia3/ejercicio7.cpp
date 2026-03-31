#include <iostream>
using namespace std;
/*7. Realice una función que dado un vector dinámico de enteros, remueva una cantidad de
elementos pasados por parámetros. Dicha función debe comenzar a eliminar elementos
desde el final.*/

void eliminarElementosDesdeFinal(int* &vec, int &tam, int cantidad) {
    if (cantidad > tam) {
        cantidad = tam; // No eliminar más elementos de los que existen
    }
    tam -= cantidad; // Reducir el tamaño del vector
    // No es necesario eliminar físicamente los elementos, solo ajustar el tamaño
}

int main() {
    
    return 0;
}