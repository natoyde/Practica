#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

struct strjugador {
    int nro;
    char nombre[200];
};

struct strlogro {
    int nro_jugador;
};

class Nivel{
    private:
    
    public:
        virtual int calcularpuntos(int logros)=0;
        virtual string getnombrenivel()=0;
        virtual ~Nivel();

};

class Junior : public Nivel {
    private:

    public:
        int calcularpuntos(int logros) override{
            return logros*10;
        }
        string getnombrenivel() override{
            return "Junior";
        }
};

class SemiSr : public Nivel{
    private:

    public:
        int calcularpuntos(int logros) override{
            return logros*5;
        }
        string getnombrenivel() override{
            return "SemiSr";
        }
};

class Senior : public Nivel{
    private:

    public:
        int calcularpuntos(int logros) override{
            int base= logros*2;
            int bonus=logros/10;
            return base+bonus;
        }
        string getnombrenivel() override{
            return "Senior";
        }
};

class Jugador{
    private:
        int nro;
        string nombre;
        int cantidadlogros;
        Nivel* nivel;
    public:
        Jugador(int n, string nom){
            nro=n;
            nombre=nom;
            cantidadlogros=0;
            nivel= new Junior();
        }
        void agregarlogro(){
            cantidadlogros++;
        }
        int calcularpuntos(){
            return nivel->calcularpuntos(cantidadlogros);
        }
        void actualizarnivel(){
            int puntos=calcularpuntos();
            delete nivel;
            if (puntos>=1000){
                nivel=new Senior;
            }else if (puntos>=100){
                nivel= new SemiSr;
            }else {
                nivel=new Junior;
            }
        }
        int getnro(){ return nro; }
        string getnombre(){ return nombre; }
        int getlogro(){ return cantidadlogros; }
        string getnivel(){ return nivel->getnombrenivel(); }

};

ostream &operator<<(ostream& os, Jugador& j){
    os<<j.getnombre()
    <<". nivel: "<<j.getnivel()
    <<". logros: "<<j.getlogro()
    <<". Puntos: "<<j.calcularpuntos();
    return os;
}

class Gestor{
    private:
        vector<Jugador*>jugadores;
    public:
        void leerarch(){
            ifstream archivoj("jugador.dat", ios::binary);
            strjugador aux_j;
            while (archivoj.read((char*)&aux_j,sizeof(strjugador))){
                jugadores.push_back(new Jugador(aux_j.nro, aux_j.nombre));
            }
            archivoj.close();

            ifstream archivol("logros.dat",ios::binary);
            strlogro aux_l;
             while (archivol.read((char*)&aux_l,sizeof(strjugador))){
                for (int i = 0; i < jugadores.size(); i++){
                    if(jugadores[i]->getnro()==aux_l.nro_jugador){
                        jugadores[i]->agregarlogro();
                    }
                }
             }
             archivol.close();
             for (size_t i = 0; i < jugadores.size(); i++){
                jugadores[i]->actualizarnivel();
             }    
        }
        //* Funciones STL
        void jugadoresconmaspuntos(){
            if (jugadores.empty()){ return; }
            auto it=max_element(jugadores.begin(), jugadores.end(),
                [](Jugador* a, Jugador* b){
                    return a->calcularpuntos() < b->calcularpuntos();
                }
            );

            int maxpuntos = (*it)->calcularpuntos();
            for (int i = 0; i < jugadores.size(); i++){
                if(jugadores[i]->calcularpuntos()==maxpuntos){
                    cout<<*jugadores[i]<<endl;
                }
            }
        }

        void cantidadpornivel(){
            map<string, int> contador;
            for (int i = 0; i < jugadores.size(); i++){
                contador[jugadores[i]->getnivel()]++;
            }
            for (auto it=contador.begin();it!=contador.end();it++){
                cout<<it->first<<" : "<<it->second<<endl;
            }
        }
    
        void nombrerepetidos(){
             map<string, int> contador;
            for(size_t i=0; i<jugadores.size();i++){
                contador[jugadores[i]->getnombre()]++;
            }

            bool hay=false;

            for (auto it=contador.begin();it!=contador.end();it++){
                if (it->second>1){
                    cout<<"nombre repetidos"
                    <<it->first
                    <<"("<<it->second<<" veces)"
                    <<endl;
                    hay=true;
                }
            }
            if (!hay){
                cout<<"no hay nombres repetidos";
            }
        }

        ~Gestor(){
            for (size_t i = 0; i < jugadores.size(); i++){
                delete jugadores[i];
            }
        }
};


int main() {
    
    return 0;
}