#include <iostream>
using namespace std;
/*Ejercicio 10
Hacer un programa que calcule y muestre el total a pagar por la compra de
pantalones, se debe pedir como entrada el valor del pantalón y la cantidad de
pantalones comprados, además si se compra 5 pantalones o mas se le aplica un
descuento de 25% al monto total a pagar y si son menos de 5 pantalones el descuento
es de 10% al monto total a pagar..
*/

float calcularmonto(float valorpantalon, int cant){
    float total;
    float descuento;
    if(cant>=5){
        total=(valorpantalon*cant);
        descuento=total*0.25;
        total=total-descuento;
    }else{
        total=(valorpantalon*cant);
        descuento=total*0.1;
        total=total-descuento;
    }
    return total;
}

int main() {
    int n=calcularmonto(100, 4);
    cout<<"el descuento es de:"<<n<<endl;
    return 0;
}