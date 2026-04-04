#include <iostream>
#include <cctype>
using namespace std;
/*3. Realice una función que dado un vector de ctring y un carácter agregue dicho 
carácter al final vector cstring.*/
void agregarCaracter(char* vec[], int n, char c) {
    for (int i = 0; i < n; i++) {
        int j = 0;

        // buscar el final del string
        while (vec[i][j] != '\0') {
            j++;
        }

        // agregar el carácter
        vec[i][j] = c;
        vec[i][j + 1] = '\0'; // nuevo final del string
    }
}

int main() {
    char str1[10] = "hola";
    char str2[10] = "mundo";
    char str3[10] = "cpp";

    char* vec[] = {str1, str2, str3};

    int n = 3;

    agregarCaracter(vec, n, '!');

    for (int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }

    return 0;
}