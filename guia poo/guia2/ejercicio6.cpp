#include <iostream>
using namespace std;
/*6. Realice una funcion que dado un vector lo transforme de modo tal
 que el primer elemento sea el ultimo y el ultimo el primero, el 
 segundo el ante penultimo, etc. utilice recursividad*/

int transformar(int vec[], int pos, int cant){
    if (pos>=cant){
        return vec[10];
    }
    
    int aux=vec[pos];
    vec[pos]=vec[cant];
    vec[cant]=aux;
    return transformar(vec, pos+1, cant-1);
}


int main() {
    int vec[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec[10]=transformar(vec, 0, 9);
    for (int i = 0; i < 10; i++){
        cout<<vec[i]<<" ";
    }
    
    return 0;
}