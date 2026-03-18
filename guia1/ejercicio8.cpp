#include <iostream>
using namespace std;
/*Ejercicio 8
Escriba una función recursiva para calcular la potencia de exponente entero de un
número. La potencia puede ser negativa. Pruebe la función en un programa C++.
Recuerde que an=a * an-1
*/
float potencia(float a, int n){
    if (n==0){
        return 1;
    }
    else if (n>0){
        return a*potencia(a,n-1);
    }
    else{
        return 1/potencia(a,-n);
    }
}
int main() {
    float a=2;
    int n=3;
    float resultado=potencia(a,n);
    cout<<"el resultado es:"<<resultado;
    return 0;
}