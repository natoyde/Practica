#include <iostream>
#include <cmath>
using namespace std;
/*Ejercicio 1
Escriba los prototipos de funciones C++ que cumplan con las características siguientes.
Proponga Ud. los elementos no especificados en el enunciado:
a) Una función llamada division_entera() que devuelve el cociente entero y el resto
de la división entre 2 enteros (int).
b) Nombre de la función: facto(). Propósito: calcular el factorial de un número (int).
c) Función hipot() que devuelve la hipotenusa de un triángulo rectángulo.
d) Función intercambio() que permite intercambiar los contenidos de 2 parámetros
tipo char, modificando simultáneamente los 2 parámetros de llamada. No devuelve
otro resultado.
 */
float division_entera(float a, float b, float &resto){
    int entero=a/b;
    resto=a/b-entero;
    return entero;
}
int facto(int n){
    if (n==0) return 1;
    return n*facto(n-1);
}
float hipot(float a, float b){
    int hipotenusa=a*a+b*b;
    int z=sqrt(hipotenusa);
    return z;
}
void intercambio(char &a, char &b){
    char aux=a;
    a=b;
    b=aux;
}
int main() {
    int a=10, b=3;
    float resto;
    cout<<"Cociente: "<<division_entera(a,b,resto)<<endl;
    cout<<"Resto: "<<resto<<endl;
    int n=5;
    cout<<"Factorial de "<<n<<": "<<facto(n)<<endl;
    float c=3, d=4;
    cout<<"Hipotenusa de "<<c<<" y "<<d<<": "<<hipot(c,d)<<endl;
    char x='A', y='B';
    intercambio(x,y);
    cout<<"intercambio: "<<x<<" "<<y<<endl;
    return 0;
}