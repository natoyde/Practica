#include <iostream>
using namespace std;
/*9. Realice una función que dado un vector dinámico de enteros, retorne una matriz que
contenga en una fila el número y el número de repeticiones de dicho número.*/


void contarRepeticiones(int* vec, int tam, int** &matriz, int &filas) {
    filas = 0;
    for (int i = 0; i < tam; i++) {
        bool encontrado = false;
        for (int j = 0; j < filas; j++) {
            if (matriz[j][0] == vec[i]) {
                matriz[j][1]++;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            int** nuevaMatriz = new int*[filas + 1];
            for (int k = 0; k < filas; k++) {
                nuevaMatriz[k] = matriz[k];
            }
            nuevaMatriz[filas] = new int[2]{vec[i], 1};
            delete[] matriz;
            matriz = nuevaMatriz;
            filas++;
        }
    }
}
int main() {
    
    return 0;
}