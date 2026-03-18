#include <iostream>
using namespace std;

/*Ejercicio 2
Escribir un programa C++ que calcule el importe de una factura sabiendo que el IVA
a aplicar es del 13% y que si el importe bruto de la factura es superior a 50, se debe
realizar un descuento del 5%.*/

int calcular_importe(float importe_bruto) {
    float importe_neto;
    if (importe_bruto > 50) {
        importe_neto = importe_bruto * 0.95; // Aplicar descuento del 5%
    } else {
        importe_neto = importe_bruto;
    }
    return importe_neto * 1.13; // Aplicar IVA del 13%
}
int main() {
    float importe_bruto;
    cout << "Ingrese el importe bruto de la factura: ";
    cin >> importe_bruto;
    cout << "El importe neto de la factura es: " << calcular_importe(importe_bruto) << endl;
    return 0;
}