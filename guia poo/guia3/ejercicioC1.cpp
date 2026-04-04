#include <iostream>
#include <cctype>   // para toupper
using namespace std;
/*1. Realice una función que dado un vector de cstring retorne el mismo cstring 
en mayúscula. */



void aMayusculas(char* vec[], int n) {
    for (int i = 0; i < n; i++) {          // recorre el vector de strings
        for (int j = 0; vec[i][j] != '\0'; j++) {  // recorre cada string
            vec[i][j] = toupper(vec[i][j]);
        }
    }
}

int main() {
    char str1[] = "hola";
    char str2[] = "mundo";
    char str3[] = "c++";

    char* vec[] = {str1, str2, str3};

    int n = 3;

    aMayusculas(vec, n);

    for (int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }

    return 0;
}