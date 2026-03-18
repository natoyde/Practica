#include <iostream>
using namespace std;
/*7.Realice una funcion que dado un vector de enteros retorne verdadero
si es palindromo, ejemplo: {1, 2, 3, 2, 1} es palindromo */

bool palindromo(int vec[], int pos, int cant){
    if (pos>=cant){
        return true;
    }
    if (vec[pos]!=vec[cant]){
        return false;
    }
    return palindromo(vec, pos+1, cant-1);
}

int main() {
    int vec[]={1, 2, 3, 2, 1};
    if (palindromo(vec, 0, 4)){
        cout<<"Es palindromo"<<endl;
    } else {
        cout<<"No es palindromo"<<endl;
    }
    return 0;
}