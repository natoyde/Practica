#include <iostream>
using namespace std;
/*8. Realice que dado dos vectores enteros los concatene. Utilice recursividad.*/

int completar(int vec1[], int vec2[], int vec3[], int pos1, int pos2, int pos3){
    if (pos1>=5 && pos2>=5){
        return vec3[10];
    }
    if (pos1<5){
        vec3[pos3]=vec1[pos1];
        return completar(vec1, vec2, vec3, pos1+1, pos2, pos3+1);
    }
    if (pos2<5){
        vec3[pos3]=vec2[pos2];
        return completar(vec1, vec2, vec3, pos1, pos2+1, pos3+1);
    }
}

int main() {
    int vec1[]={1, 3, 5, 7, 9} ;
    int vec2[]={2, 4, 6, 8, 10};
    int vec3[10];
    completar(vec1, vec2, vec3, 0, 0, 0);
    for (int i = 0; i < 10; i++){
        cout<<vec3[i]<<" ";
    }
    return 0;
}