#include <iostream>
using namespace std;
/*1. realice un metodo que retorne el acumulado de un vector de 10 enteros.
Utilice recursividad
*/

int acumulado(int v[], int n){
    if (n==0) return 0;
    return v[n-1]+acumulado(v,n-1);
}

int main() {
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "El acumulado es: " << acumulado(v, 10) << endl;
    return 0;
}