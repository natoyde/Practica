#include <iostream>
#include <cstring>
using namespace std;
/*15. Realice una función que dado un vector de cstring y un carácter devuelva un vector
de cstring con el conjunto de palabras separadas por este carácter. Por ejemplo dado 
“hola Mundo” y ‘ ‘ retorne “hola” y “Mundo”*/

void separarPalabras(const char* frase, char separador) {
    // Aquí se implementaría la lógica para separar las palabras de la frase utilizando el separador dado
    const char* palabra = strtok(const_cast<char*>(frase), &separador); // Utilizar strtok para separar las palabras
    while (palabra != nullptr) {
        cout << palabra << endl; // Imprimir cada palabra separada
        palabra = strtok(nullptr, &separador); // Obtener la siguiente palabra
    }
}

int main() {
    const char* frase = "hola Mundo";
    char separador = ' ';
    separarPalabras(frase, separador);

    return 0;
}