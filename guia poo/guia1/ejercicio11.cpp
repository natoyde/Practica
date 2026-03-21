#include <iostream>
using namespace std;
/*Ejercicio 11
Dado un valor numérico ingresado por pantalla, indicar si el número es primo o no
*/

bool esPrimo(int numero) {
    if (numero <= 1) {
        return false; // Los números menores o iguales a 1 no son primos
    }
    for (int i = 2; i <= numero / 2; i++) {
        if (numero % i == 0) {
            return false; // Si el número es divisible por algún número entre 2 y su mitad, no es primo
        }
    }
    return true; // Si no se encontró ningún divisor, el número es primo
}

int main() {
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    if (esPrimo(numero)) {
        cout << "El numero es primo." << endl;
    } else {
        cout << "El numero no es primo." << endl;
    }
    return 0;
}