#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
using namespace std;

struct strempleado{
    int id;
    char nombre[200];
    double sueldoneto;
    int aniosantiguedad;
    int empleadosacargo;
};

class Empleado{
    protected:
        int id;
        string nombre;
        double sueldoneto;
        int aniosantiguedad;
        int empleadosacargo;
    public:
        Empleado(int id, string nom, double sueldo, int antiguedad, int empleados);
        int getid(){
            return id;
        }
        string getnombre(){
            return nombre;
        }
        int getantiguedad(){
            return aniosantiguedad;
        }
        double calcularsalario(){
            double salario = sueldoneto;
            salario+=sueldoneto*(aniosantiguedad*0.01);
            salario+=empleadosacargo*1000;
            return salario;
        }
};

class Gestor{
    private:
        vector<Empleado>vec_emp;
    public:
        void leerarch(){
            ifstream arch1("empleados.dat", ios::binary);
            strempleado aux;
            while (arch1.read((char*)&aux,sizeof(aux))){
                string nom(aux.nombre);

                Empleado nuevo(aux.id, nom, aux.sueldoneto,aux.aniosantiguedad,aux.empleadosacargo);

                vec_emp.push_back(nuevo);
            }
            arch1.close();
        }

        void guardartxt(){
            ofstream arch2("salario.txt");
            for (int i = 0; i < vec_emp.size(); i++){
                arch2<<vec_emp[i].getnombre()
                <<""
                <<vec_emp[i].calcularsalario()
                <<endl;
            }
            arch2.close();
        }

        void menorsalario(){
            auto it=min_element(
                vec_emp.begin(),
                vec_emp.end(),
                [](Empleado a, Empleado b){
                    return a.calcularsalario()<b.calcularsalario();
                }
            );
            double minsal= it->calcularsalario();

            for (int i = 0; i < vec_emp.size(); i++){
                if(vec_emp[i].calcularsalario()==minsal){
                    cout<<vec_emp[i].getnombre()
                    <<"cobra"
                    <<vec_emp[i].calcularsalario()
                    <<endl;
                }
            }   
        }
        double montototal(){
            return accumulate(
                vec_emp.begin(),
                vec_emp.end(),
                0.0,
                [](double suma, Empleado e){
                    return suma+e.calcularsalario();
                }
            );
        }
};






int main() {
    
    return 0;
}