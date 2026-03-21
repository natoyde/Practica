#include <iostream>
using namespace std;
/*Ejercicio 16
Determinar si un año es bisisiesto
Recordar: Un año es bisiesto si es divisible por 4, excepto los años de siglo (aquellos
divisibles por 100), que para ser bisiestos, también deben ser divisibles por 400.
*/

bool bisiesto(int anio){
    if(anio%4==0){
        if(anio>=100){
            if (anio % 100 != 0 || anio % 400 == 0) {
                return true; // El año es bisiesto
            } else {
                return false; // El año no es bisiesto
            }
        }    
        return true;
    } else {
        return false;
    }
}
int main() {
    int anio;
    cout << "Ingrese un anio: ";
    cin >> anio;
    if (bisiesto(anio)) {
        cout << "El anio es bisiesto." << endl;
    } else {
        cout << "El anio no es bisiesto." << endl;
    }
    return 0;
}