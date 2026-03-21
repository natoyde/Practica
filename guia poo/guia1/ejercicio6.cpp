#include <iostream>
using namespace std;
/*Ejercicio 6
a) Escriba una función C++ que determine el interés a obtener por un depósito de
dinero en un banco a interés compuesto. Se conoce el período en meses (n), la tasa
de interés mensual (i) y el monto inicial o capital a depositar (c).
b) Utilice la función en un programa que permita el ingreso del monto inicial del
depósito y la tasa de interés e informe para distintos períodos (2 a 24 meses) el total
que debe reintegrar el banco.*/

float interes_total(int n, float i, float c){
    for (int j = 0; j < n; j++){
      c=c+c*i;  
    }
    return c;
}

int main() {
    int periodo=3;
    float interes=0.5;
    float monto= 100;
    int montofinal=interes_total(periodo, interes, monto);
    cout<<"el monto final es:"<<montofinal;
    return 0;
}