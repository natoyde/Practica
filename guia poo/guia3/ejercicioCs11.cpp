#include <iostream>
#include <cstring>
using namespace std;
/*11. Realice una función que dado un vector de cstring devuelva un vector con las 
palabras que terminen con una letra ingresada por parámetros*/

void palabrasQueTerminanConLetra(const char** vector, int size, char letra) {
    // Aquí se implementaría la lógica para filtrar las palabras que terminan con la letra dada
    for (int i = 0; i < size; i++) {
        // Verificar si la última letra de la palabra es igual a 'letra'
        int len = strlen(vector[i]);
        if (len > 0 && vector[i][len - 1] == letra) {
            cout << vector[i] << endl; // Imprimir la palabra que cumple la condición
        }
    }

}

int main() {
    const char* palabras[] = {"hola", "mundo", "casa", "perro"};
    int size = sizeof(palabras) / sizeof(palabras[0]);
    char letra = 'o';
    palabrasQueTerminanConLetra(palabras, size, letra);
    for (int i = 0; i < size; i++) {
        cout << "Liberando memoria para: " << palabras[i] << endl;
        delete[] palabras[i]; // Liberar la memoria asignada a cada palabra
    }
    return 0;
}