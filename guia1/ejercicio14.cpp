#include <iostream>
using namespace std;

/*Ejercicio 14
Escriba una función recursiva para calcular el máximo común divisor (m.c.d.)de dos
números enteros dados aplicando las propiedades recurrentes.
Si a>b, entonces m.c.d.(a,b)=m.c.d.(a-b,b)
Si a<b, entonces m.c.d.(a,b)=m.c.d.(a, b-a)
Si a=b, entonces m.c.d.(a,b)=m.c.d.(b,a)=a=b
*/

int mcd(int a, int b){
    if (b == 0){
        return a;
    }
    else {
        return mcd(b, a%b);
    }
}
int main(){

    int resultado;
    int a = 40;
    int b = 8;
    int n = 0;

    if (a > b){
        n = a - b;
        resultado = mcd(n, b);
    }

    if (a < b){
        n = b - a;
        resultado = mcd(n, b);
    }

    if (a == b){
        resultado = mcd(b, a);
    }
    cout<<resultado<<endl;
    return 0;
}