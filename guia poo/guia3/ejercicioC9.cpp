#include <iostream>
using namespace std;

int longitud(char* str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int buscarPrimeraOcurrencia(char arr[][50], int tam, char c) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < longitud(arr[i]); j++) {
            if (arr[i][j] == c) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    char palabras[][50] = {"hola", "mundo", "cpp", "vector"};
    int tam = 4;

    char buscar = 'p';
    int resultado = buscarPrimeraOcurrencia(palabras, tam, buscar);

    if (resultado != -1)
        cout << "Primera ocurrencia de '" << buscar << "' en el indice: " << resultado << endl;
    else
        cout << "Caracter '" << buscar << "' no encontrado. Retorna: " << resultado << endl;

    buscar = 'z';
    resultado = buscarPrimeraOcurrencia(palabras, tam, buscar);

    if (resultado != -1)
        cout << "Primera ocurrencia de '" << buscar << "' en el indice: " << resultado << endl;
    else
        cout << "Caracter '" << buscar << "' no encontrado. Retorna: " << resultado << endl;

    return 0;
}