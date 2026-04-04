#include <iostream>
using namespace std;

/*7. Realice una función que dado un vector de ctring y un entero retorne la subcadena que esta
formada por desde el entero pasado por parámetros hasta el fin de la cadena .*/

char** subcadenasDesdePos(char* vec[], int n, int pos) {
    char** resultado = new char*[n];

    for (int i = 0; i < n; i++) {
        int len = 0;

        // calcular longitud total
        while (vec[i][len] != '\0') {
            len++;
        }

        // si la posición es inválida
        if (pos >= len) {
            resultado[i] = new char[1];
            resultado[i][0] = '\0';
            continue;
        }

        // tamaño de la subcadena
        int nuevaLen = len - pos;

        resultado[i] = new char[nuevaLen + 1];

        int j = pos;
        int k = 0;

        while (vec[i][j] != '\0') {
            resultado[i][k] = vec[i][j];
            j++;
            k++;
        }

        resultado[i][k] = '\0';
    }

    return resultado;
}

int main() {
    char str1[] = "hola";
    char str2[] = "mundo";
    char str3[] = "casa";

    char* vec[] = {str1, str2, str3};

    int n = 3;
    int pos = 3;

    char** res = subcadenasDesdePos(vec, n, pos);

    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
        delete[] res[i]; // liberar cada string
    }

    delete[] res;

    return 0;
}