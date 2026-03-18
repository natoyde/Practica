#include <iostream>
using namespace std;
/*Ejercicio 9
La serie de Fibonacci se calcula de la forma siguiente:
1 + 1 + 2 + 3 + 5 + 8 + 13 +…
Donde cada término i se calcula sumando los 2 anteriores: ti=ti-1+ti-2, y los 2 términos
iniciales valen 1.
Escriba una función recursiva para calcular la serie de Fibonacci y luego escriba un
programa cliente que la utilice. */

int figonacci(int n){
    int faa=0;
    int fa=1;
    int aux=faa;
    for (int i = 0; i < n; i++){
        aux=faa;
        faa=fa;
        fa=faa+aux;
    }
   return faa; 
}


int main() {
    int numero=6;
    int resultado=figonacci(numero);
    cout<<resultado;
    return 0;
}