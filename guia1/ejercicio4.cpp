#include <iostream>
using namespace std;
/*Ejercicio 4
Escriba 3 funciones sobrecargando el nombre intercambio(..) de modo que cada una
de ellas pueda ser invocada y produzca el intercambio de 2 datos que se pasan
como parámetros: 2 datos de tipo char, 2 datos enteros, dos arreglos de flotantes.
*/

void intercambio_char(char &a, char &b){
    char aux=a;
    a=b;
    b=aux; 
}
void intercambio_int(int &c, int &d){
    int aux=c;
    c=d;
    d=aux;
}
void intercambio_float(float &e, float &f){
    float aux=e;
    e=f;
    f=aux;
}
int main() {
    char x='a', y='b';
    int num1=5, num2 =6;
    float flotante1=2.5, flotante2 =6.3;
    cout<<"normal_char:"<<x<<"-"<<y<<endl;
    cout<<"normal_int:"<<num1<<"-"<<num2<<endl;
    cout<<"normal_float: "<<flotante1<<"-"<<flotante2<<endl;
    intercambio_char(x,y);
    intercambio_int(num1, num2);
    intercambio_float(flotante1, flotante2);
    cout<<"intercambio_char:"<<x<<"-"<<y<<endl;
    cout<<"intercambio_int:"<<num1<<"-"<<num2<<endl;
    cout<<"intercambio_float:"<<flotante1<<"-"<<flotante2<<endl;
    return 0;
}