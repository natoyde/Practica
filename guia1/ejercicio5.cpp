#include <iostream>
using namespace std;
/*Ejercicio 5
Escriba un programa que utilice una función llamada formalinea() que reciba 2
parámetros: uno de tipo entero y otro de tipo char. El programa debe escribir una
línea con tantos caracteres repetidos como indique el parámetro entero. El 2do
parámetro es opcional; si no se lo especifica en la llamada debe emplear ‘#’ para
formar la secuencia.
Ejemplo de llamadas:
formalinea(7,’-‘); debe mostrar: -------
formalinea(10); debe escribir: ##########
*/
void formalinea(int num, char signo='#'){

    for (int i = 0; i < num; i++){
        cout<<signo;
    }
}


int main() {
    int numero=5;
    char signos='a';
    formalinea(numero, signos);
    return 0;
}