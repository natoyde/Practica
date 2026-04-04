#include <iostream>

using namespace std;

/*6. Realice una función que dado un vector de ctring y un carácter elimine todas las 
ocurrencias. */

void eliminarTodasOcurrencias(char* vec[], int n, char c) {
    for (int i = 0; i < n; i++) {
        int j = 0; // recorre original
        int k = 0; // arma el nuevo string

        while (vec[i][j] != '\0') {
            if (vec[i][j] != c) {
                vec[i][k] = vec[i][j];
                k++;
            }
            j++;
        }

        vec[i][k] = '\0'; // cerrar correctamente
    }
}

int main() {
    char str1[10] = "banana";
    char str2[10] = "manzana";
    char str3[10] = "casa";

    char* vec[] = {str1, str2, str3};

    int n = 3;

    eliminarTodasOcurrencias(vec, n, 'a');

    for (int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }

    return 0;
}