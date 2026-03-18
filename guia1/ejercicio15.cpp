#include <iostream>
using namespace std;
/*Ejercicio 15
Escriba un programa C++ que exhiba en pantalla el siguiente menú:
 CALCULOS
A- Calcular el doble del dato.
B- Determinar si es par.
C- Determinar si es primo.
D- Salir.
 Elija una Opción (A..DE): _
El programa debe ingresar un dato y presentar el menú. Luego, de acuerdo a la
selección el usuario debe resolver las opciones propuestas en el menú. Además
debe validar la entrada de la opción (A..D) indicando un mensaje de error si
corresponde. Resuelva cada opción del menú con una función C++ creada por Ud
*/
int calculardoble(int numero){
    numero=numero*2;
    return numero;
}

bool par(int numero){
    if (numero % 2 == 0) {
        return true; // El número es par
    } else {
        return false; // El número es impar
    }
}

bool impar(int numero){
    if (numero <= 1) {
        return false; // Los números menores o iguales a 1 no son primos
    }
    for (int i = 2; i <= numero / 2; i++) {
        if (numero % i == 0) {
            return false; // Si el número es divisible por algún número entre 2 y su mitad, no es primo
        }
    }
    return true; // Si no se encontró ningún divisor, el número es primo
}
int main() {
    int numero;
    int dato=9;
    int n;
    cout<<"ingrese el numero: ";
    cin>>numero;
    
    while(dato!=4){
        cout<<"Calculos: "<<endl;
        cout<<"A - Calcular el doble del dato"<<endl;
        cout<<"B - Determinar si es par"<<endl;
        cout<<"C - Determinar si es impar"<<endl;
        cout<<"D - Salir"<<endl;
        cout<<"ingrese la opcion: ";
        cin>>dato;
        switch (dato)
        {
        case 1:
            n=calculardoble(numero);
            cout<<"el doble de "<<numero<<" es: "<<n<<endl;
            break;
        case 2:
            n=par(numero);
            if(n==1){
                cout<<"el numero es par"<<endl;
            }else{
                cout<<"el numero no es par"<<endl;
            }
            break;
        case 3:
            n=impar(numero);
            if(n==1){
                cout<<"el numero es impar"<<endl;
            }else{
                cout<<"el numero no es impar"<<endl;
            }
            break;

        }
    }
    cout<<"adios";
    return 0;
}