#include <iostream>
using namespace std;
/*1. Realice una clase que represente números complejos.
a) Un número complejo debe ser construido.
b) Un número complejo debe sumar, restar, multiplicar y dividir*/
class Complejos{
    private:
    // atributos
        int num;
        int potencia;
    public:
    // metodos
        Complejos(int num, int potencia); 
        int getnum(){
            return num;
        }
        int getpotencia(){
            return potencia;
        }
        Complejos suma(Complejos otra);
        Complejos restar(Complejos otra);
        Complejos multiplicar(Complejos otra);
        Complejos dividir(Complejos otra);
};

Complejos::Complejos(int num, int potencia){
    this->num=num;
    this->potencia=potencia;
}
Complejos Complejos::suma(Complejos otra){
    if (this->potencia==otra.potencia){
        int nro = this->num + otra.num;
        return Complejos(nro, potencia);
    }
    return Complejos(0, 0);
}
Complejos Complejos :: restar(Complejos otra){
    if (this->potencia==otra.potencia){
        int nro = this->num - otra.num;
        return Complejos(nro, potencia);
    }
     return Complejos(0, 0);
}
Complejos Complejos :: multiplicar(Complejos otra){
        int pto= this->potencia+otra.potencia;
        int nro = (float)this->num * otra.num;
        return Complejos(nro, pto);
}
Complejos Complejos :: dividir(Complejos otra){
        float pto= this->potencia-otra.potencia;
        float nro = this->num / otra.num;
        return Complejos(nro, pto);
}



int main() {
    Complejos unComplejo(4,3);
    Complejos otroComplejo(2,2);
    Complejos resultadosuma = unComplejo.suma(otroComplejo);
    cout << resultadosuma.getnum() <<"i^" << resultadosuma.getpotencia() << endl;
    Complejos resultadoresta = unComplejo.restar(otroComplejo);
    cout << resultadoresta.getnum() <<"i^" << resultadoresta.getpotencia() << endl;
    Complejos resultadomulti = unComplejo.multiplicar(otroComplejo);
    cout << resultadomulti.getnum() <<"i^" << resultadomulti.getpotencia() << endl;
    Complejos resultadodividir = unComplejo.dividir(otroComplejo);
    cout << resultadodividir.getnum() <<"i^" << resultadodividir.getpotencia() << endl;

    return 0;
}