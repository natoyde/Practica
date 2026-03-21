#include <iostream>
using namespace std;
/*5. Realice un metodo que retorne el valor del triangulo de pascal en la
posicion determinada por parametros
el triangulo de pascal viene de la siguiente forma
1
11
121
1331
14641
...
el metodo debe retornar 3 para los parametros: columna 2, fila 4.*/
int valor(int col, int fil){
    if (col==0 || col==fil) return 1;
    return valor(col-1, fil-1)+valor(col, fil-1);
}


int main() {
    cout << "El valor en la columna 2, fila 4 es: " << valor(2, 4) << endl;
    return 0;
}