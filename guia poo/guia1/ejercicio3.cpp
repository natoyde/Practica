#include <iostream>
using namespace std;
/*Ejercicio 3
Se ingresan los nombres y edades de los 457 miembros de una asociación
cooperadora. Determinar el nombre y la edad del mayor de los integrantes.
Validar la entrada de los datos correspondientes a las edades, los cuales deben estar
dentro el rango 12..90, con una función llamada validar_edad() en la cual, al
verificarse una edad fuera del rango, se debe indicar un mensaje de error y permitir el
reingreso del dato. 
*/

void validar_edad(){
    int edad;
    cout << "Ingrese la edad del miembro: ";
    cin >> edad;
    while (edad < 12 || edad > 90) {
        cout << "Edad inválida. Por favor, ingrese una edad entre 12 y 90: ";
        cin >> edad;
    }
}

int main() {
    validar_edad();
    return 0;
}