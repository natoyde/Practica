#include <iostream>
using namespace std;
/*4. Realice una función que dado un vector de ctring y un carácter agregue dicho 
carácter al principio del vector cstring*/

void agregarCaracter(char* vec[], int n, char c) {
    for (int i = 0; i < n; i++) {
        int j = 0;

        while (vec[i][j] != '\0') {
            j++;
        }


        for (int k = j; k >= 0; k--){
            vec[i][k+1]=vec[i][k];
        }
        
        // agregar el carácter
        vec[i][0] = c;
    }
}

int main() {
    char str1[10] = "hola";
    char str2[10] = "mundo";
    char str3[10] = "cpp";

    char* vec[] = {str1, str2, str3};

    int n = 3;

    agregarCaracter(vec, n, '?');

    for (int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }

    return 0;
}