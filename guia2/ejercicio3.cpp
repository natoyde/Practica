#include <iostream>
using namespace std;
/*3. Realice un metodo que retorne el mayor elemento de un vector de 10 enteros. 
Utilizar recursividad
*/

int menorelemento(int vec[], int pos, int cant, int mayor){
    if(mayor<vec[pos]){
        mayor=vec[pos];
    }
    
    if (pos==cant){
        return mayor;
    }
    return menorelemento(vec, pos+1, cant, mayor);
}

int main() {
    int vec[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=menorelemento(vec, 0, 9, 0);
    cout<<"el mayor elemento es: "<<n;
    return 0;
}