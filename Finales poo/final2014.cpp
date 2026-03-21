#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

    struct strcliente{
        int id_c;
        char nombre[200];
        char tipo[1];
    };

    struct strventa{
        int nro_c;
        int cant;
        double montototal;
    };



class Venta{
    private:
        int nro_c;
        int cant;
        double montototal;
    public:
        Venta(int nro_c, int cant, double montototal);
        int getnum(){
            return nro_c;
        }
        int getcant(){
            return cant;
        }
        double getmontototal(){
            return montototal;
        }
};

Venta :: Venta(int nro_c, int cant, double montototal){
    this-> nro_c=nro_c;
    this-> cant=cant;
    this-> montototal=montototal;
}

class Cliente{
    private:
        int id_c;
        string nombre;
        string tipo;
        vector<Venta> vec_venta;



};




















int main() {
    
    return 0;
}