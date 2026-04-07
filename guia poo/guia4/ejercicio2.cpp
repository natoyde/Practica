#include <iostream>
using namespace std;
/*2. Realice una clase que represente una Fracción.
a) Un objeto fracción solo se puede construir a partir de un numerador y denominador.
b) Un objeto fracción debe poder sumar, restar, multiplicar y dividir.
c) Un objeto fracción debe poder simplificarse
*/
class Fraccion {
    private:
        int n;
        int d;
        int mcd(int n, int d);
    public:
        Fraccion(int n, int d);
        Fraccion(int n);
        Fraccion suma(Fraccion otra);
        Fraccion restar(Fraccion otra);
        Fraccion multiplicar(Fraccion otra);
        Fraccion dividr(Fraccion otra);
        int getN() const{
            return n;
        }
        int getD() const{
            return d;
        }
};

int Fraccion::mcd(int n, int d){
    return ((n % d) == 0) ? d : mcd(d,n%d);
}

Fraccion::Fraccion(int n, int d){
    int nroMcd = this->mcd(n, d);
    this->d = d/nroMcd;
    this->n = n/nroMcd;
}

Fraccion::Fraccion(int n) : Fraccion(n,1)
{
}

Fraccion Fraccion::suma(Fraccion otra){
    int nro = this->n * otra.d + this->d * otra.n;
    int deno = this->d * otra.d;
    return Fraccion(nro, deno);
}

Fraccion Fraccion::restar(Fraccion otra){
    int nro = this->n * otra.d - this->d * otra.n;
    int deno = this->d * otra.d;
    return Fraccion(nro, deno);
}

Fraccion Fraccion::multiplicar(Fraccion otra){
    int nro = this->n * otra.n;
    int deno = this->d * otra.d;
    return Fraccion(nro, deno);
}

Fraccion Fraccion::dividr(Fraccion otra){
    int nro = this->n * otra.d;
    int deno = this->d * otra.n;
    return Fraccion(nro, deno);
}

int main() {
    Fraccion unaFraccion(2,3);
    Fraccion otraFraccion(1,2);
    Fraccion resultadosuma = unaFraccion.suma(otraFraccion);
    Fraccion fraccionSimplificar(11,22);
    Fraccion resultadoresta = unaFraccion.restar(otraFraccion);
    Fraccion resultadomulti = unaFraccion.multiplicar(otraFraccion);
    Fraccion resultadodividir = unaFraccion.dividr(otraFraccion);
    
    cout << resultadosuma.getN() <<"/" << resultadosuma.getD() << endl;
    cout << resultadoresta.getN() <<"/" << resultadoresta.getD() << endl;
    cout << resultadomulti.getN() <<"/" << resultadomulti.getD() << endl;
    cout << resultadodividir.getN() <<"/" << resultadodividir.getD() << endl;
    cout << fraccionSimplificar.getN() <<"/" << fraccionSimplificar.getD() << endl;

    return 0;
}