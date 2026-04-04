#include <iostream>

using namespace std;

char** subcadenasRango(char* vec[], int n, int ini, int fin) {
    char** resultado = new char*[n];

    for (int i = 0; i < n; i++) {
        int len = 0;

        // calcular longitud
        while (vec[i][len] != '\0') {
            len++;
        }

        // validar rango
        if (ini >= len || ini > fin) {
            resultado[i] = new char[1];
            resultado[i][0] = '\0';
            continue;
        }

        // ajustar fin si se pasa
        if (fin >= len) {
            fin = len - 1;
        }

        int nuevaLen = fin - ini + 1;
        resultado[i] = new char[nuevaLen + 1];

        int k = 0;
        for (int j = ini; j <= fin; j++) {
            resultado[i][k++] = vec[i][j];
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
    int ini = 0;
    int fin = 3;

    char** res = subcadenasRango(vec, n, ini, fin);

    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
        delete[] res[i];
    }

    delete[] res;

    return 0;
}