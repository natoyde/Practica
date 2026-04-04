#include <iostream>
#include <cctype>   
using namespace std;
/*2. Realice una función que dado un vector de cstring retorne el mismo cstring 
en minúscula.*/

void aMinusculas(char* vec[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; vec[i][j] != '\0'; j++) {
            vec[i][j] = tolower(vec[i][j]);
        }
    }
}



int main() {
    char str1[] = "HOLA";
    char str2[] = "MUNDO";  
    char str3[] = "C++";

    char* vec[] = {str1, str2, str3};

    int n = 3;

    aMinusculas(vec, n);

    for (int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }


    return 0;
}