#include <iostream>
#include <cstring>
using namespace std;
/*14. Realice una función que dado un vector de cstring devuelva un vector con las letras
al reverso. */

void letrasAlReverso(const char** vector, int size) {
    // Aquí se implementaría la lógica para invertir las letras de cada palabra en el vector
    for (int i = 0; i < size; i++) {
        int len = strlen(vector[i]);
        char* reversed = new char[len + 1]; // Crear un nuevo cstring para almacenar la palabra invertida
        for (int j = 0; j < len; j++) {
            reversed[j] = vector[i][len - 1 - j]; // Invertir las letras
        }
        reversed[len] = '\0'; // Agregar el carácter nulo al final del cstring
        cout << reversed << endl; // Imprimir la palabra invertida
        delete[] reversed; // Liberar la memoria asignada para la palabra invertida
    }
}

int main() {
    const char* palabras[] = {"hola", "mundo", "casa", "perro"};
    int size = sizeof(palabras) / sizeof(palabras[0]);
    letrasAlReverso(palabras, size);
    for (int i = 0; i < size; i++) {
        cout << "Liberando memoria para: " << palabras[i] << endl;
        delete[] palabras[i]; // Liberar la memoria asignada a cada palabra
    }
    return 0;
}