#include <iostream>
#include <cstring>
using namespace std;
/*12. Realice una función que dado un vector de cstring devuelva un vector con las 
palabras que contengan un cstring ingresado por parámetros*/

void palabrasQueContienenSubstring(const char** vector, int size, const char* substring) {
    // Aquí se implementaría la lógica para filtrar las palabras que contienen el substring dado
    for (int i = 0; i < size; i++) {
        if (strstr(vector[i], substring) != nullptr) { // Verificar si el substring está presente en la palabra
            cout << vector[i] << endl; // Imprimir la palabra que cumple la condición
        }
    }
}

int main() {
    const char* palabras[] = {"hola", "mundo", "casa", "perro"};
    int size = sizeof(palabras) / sizeof(palabras[0]);
    const char* substring = "o";
    palabrasQueContienenSubstring(palabras, size, substring);
    for (int i = 0; i < size; i++)
    {
        cout << "Liberando memoria para: " << palabras[i] << endl;
        delete[] palabras[i]; // Liberar la memoria asignada a cada palabra
    }
    
    return 0;
}