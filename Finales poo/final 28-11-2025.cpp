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
        int getnro_c(){
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
    public:
        Cliente(int id_c, string nombre, string tipo);
        int getid_c(){
            return id_c;
        }
        float getmonto();
        string getnombre(){
            return nombre;
        }
        void settipo(string ntipo){
            this->tipo=ntipo;
        }
        void agregarventa(Venta nueva_venta){
            vec_venta.push_back(nueva_venta);
        }
        int cant_t(){
            int cant_totales=0;
            for (int i = 0; i < vec_venta.size(); i++){
                cant_totales+=vec_venta[i].getcant();
            }
            return cant_totales;
        }
        int cant_m(){
            int cant_totales=0;
            for (int i = 0; i < vec_venta.size(); i++){
                cant_totales+=vec_venta[i].getmontototal();
            }
            return cant_totales; 
        }
};

Cliente :: Cliente(int id_c, string nombre, string tipo){
    this-> id_c=id_c;
    this-> nombre=nombre;
    this-> tipo=tipo;
}

class Gestor{
    private:
        vector<Cliente>vec_cliente;
    public:
        Gestor();
        void leerarch();
        void cambiartipo(int id, string ngtipo){
            for (int i = 0; i < vec_cliente.size(); i++){
                if (vec_cliente[i].getid_c()==id){
                    vec_cliente[i].settipo(ngtipo);
                    break;
                }  
            }
        }
        void clientesMayorCantidaditems();
        double obtenerMontoTotalVentas();
        
};

void Gestor::leerarch(){
    ifstream archivo1;
    archivo1.open("cliente.dat", ios::binary);
    strcliente aux_c;
    while (archivo1.read((char*)&aux_c,sizeof(strcliente))){
        string nombre_str(aux_c.nombre);
        string tipo(aux_c.tipo);

        Cliente nuevocliente(aux_c.id_c,nombre_str,tipo);
        vec_cliente.push_back(nuevocliente);
    }
    
    ifstream archivo2("ventas.dat", ios::binary);
    strventa aux_v;
    while (archivo2.read((char*)&aux_v,sizeof(strventa))){
        vector<Venta>aux_venta;
        Venta nuevoventa(aux_v.nro_c, aux_v.cant, aux_v.montototal);
        aux_venta.push_back(nuevoventa);
        for (int i = 0; i < vec_cliente.size(); i++){
           for (int j = 0; j < aux_venta.size(); j++){
            if (vec_cliente[i].getid_c()==aux_venta[j].getnro_c()){
                vec_cliente[i].agregarventa(aux_venta[j]);
            }
           }
        }
    }
}

float Cliente::getmonto(){
    float canttotal=cant_t();
    float mont=cant_m();

    float descuentoAcumulado=0;
    float descCantidad=0;
    float descMonto=0;

    if (tipo == "A" || tipo == "C"){
        if(canttotal>100){
            descCantidad=mont*0.01*(canttotal/100);
        }
    }
    if (tipo== "A" || tipo == "B" || tipo == "C"){
        if (mont>=10000 && mont<20000){
            descMonto=mont*0.20;
        }else if (mont>=20000){
            descMonto=mont*0.25;
        }
    }
    if (tipo=="A"){
        descuentoAcumulado=descCantidad+descMonto;
    }else if (tipo=="B"){
        descuentoAcumulado=descMonto;
    }else if (tipo=="C"){
        descuentoAcumulado=max(descCantidad,descMonto);
    }

    return mont-descuentoAcumulado;
}

void Gestor::clientesMayorCantidaditems(){
    vector<Cliente> clientesordenados= vec_cliente;
    sort(clientesordenados.begin(),clientesordenados.end(),
        [](Cliente a, Cliente b){
            return a.cant_t()>b.cant_t();
        }
    );
    int mayor=clientesordenados[0].cant_t();
    vector<Cliente>mejoresclientes;
    for (int i = 0; i < clientesordenados.size(); i++){
        if(clientesordenados[i].cant_t()==mayor){
            mejoresclientes.push_back(clientesordenados[i]);
        }
    }
    for (int i = 0; i < mejoresclientes.size(); i++){
        cout<<"Nombre: "<<mejoresclientes[i].getnombre()<<endl;
    }
}
double Gestor::obtenerMontoTotalVentas(){
    double montototal=0;
    montototal=accumulate(vec_cliente.begin(), vec_cliente.end(),
                0.0,[](double sumaparcial, Cliente c){
                    return sumaparcial+c.cant_m();
                }
            );
}


int main() {
    
    return 0;
}