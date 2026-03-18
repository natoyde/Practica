#include <iostream>
using namespace std;
/*Ejercicio 12
Generar los números primos de un valor ingresado por el usuario. Mostrar en pantalla,
además, cuantos números primos tiene y cuales son
*/

int numeroPrimos(int numero) {
    int contador = 0;
    for (int i = 2; i <= numero; i++) {
        bool esPrimo = true;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                esPrimo = false;
                break;
            }
        }
        if (esPrimo) {
            cout << i << " ";
            contador++;
        }
    }
    return contador;
}
int main() {
    int numero;
    cout << "Ingrese un número: ";
    cin >> numero;
    int cantidad = numeroPrimos(numero);
    cout << "\nCantidad de números primos: " << cantidad << endl;
    return 0;
}