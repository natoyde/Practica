#include <iostream>
using namespace std;
/*4. Realice un metodo que retorne el menor elemento de un vector de 10 enteros.
Utilice recursividad*/
int menorelemento(int vec[], int pos, int cant, int menor){
    if(menor>vec[pos]){
        menor=vec[pos];
    }
    
    if (pos==cant){
        return menor;
    }
    return menorelemento(vec, pos+1, cant, menor);
}

int main() {
    int vec[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=menorelemento(vec, 0, 9, 100);
    cout<<"el mayor elemento es: "<<n;
    return 0;
}