#include <iostream>
using namespace std;
/*5. Realice una función que dado un vector de ctring y un carácter elimine la primer 
ocurrencia*/

void eliminarCaracter(char* vec[], int n, char c){
    for (int i = 0; i < n; i++) {
        int j = 0;

        while (vec[i][j] != '\0' && vec[i][j] != c) {
            j++;
        }

        // si lo encontró
        if (vec[i][j] == c) {
            // desplazar a la izquierda
            while (vec[i][j] != '\0') {
                vec[i][j] = vec[i][j + 1];
                j++;
            }
        }
    }
}

int main() {
    char str1[10] = "hola";
    char str2[10] = "mundo";
    char str3[10] = "casa";

    char* vec[] = {str1, str2, str3};

    int n = 3;

    eliminarCaracter(vec, n, 'a');

    for (int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }
    return 0;
}