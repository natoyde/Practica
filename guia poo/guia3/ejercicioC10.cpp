#include <iostream>
using namespace std;
/*10. Realice una función que dado un vector de cstring devuelva un vector con las palabras que
comiencen con una letra ingresada por parámetros*/

void palabrasConLetra(const char* vector[], char letra) {
    
    for (int i = 0; i < 3; i++) {
        if (vector[i][0] == letra) {
            cout << vector[i] << endl; // Imprime la palabra que comienza con la letra dada
        }
    }

}

int main() {
    const char* palabras[] = {"manzana", "banana", "mango"};
    char letra;
    cout << "Ingrese una letra: ";
    cin >> letra;
    palabrasConLetra(palabras, letra);
    
    return 0;
}