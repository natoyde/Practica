#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// ─── (1-30) TEMPLATE VECTOR DINÁMICO SIN STL ──────────────────────────────────

template <typename T>
class MiVector {
    private:
        T* datos;
        int capacidad;
        int cantidad;

        void redimensionar() {
            capacidad *= 2;
            T* nuevo = new T[capacidad];
            for (int i = 0; i < cantidad; i++)
                nuevo[i] = datos[i];
            delete[] datos;
            datos = nuevo;
        }

    public:
        MiVector() {
            capacidad = 4;
            cantidad  = 0;
            datos     = new T[capacidad];
        }

        ~MiVector() {
            delete[] datos;
        }

        void agregar(T elemento) {
            if (cantidad == capacidad)
                redimensionar();
            datos[cantidad++] = elemento;
        }

        void remover(int pos) {
            if (pos < 0 || pos >= cantidad) return;
            for (int i = pos; i < cantidad - 1; i++)
                datos[i] = datos[i + 1];
            cantidad--;
        }

        T& operator[](int pos) {
            return datos[pos];
        }

        int size() {
            return cantidad;
        }
};

// ─── (2-25) MODELADO POO ──────────────────────────────────────────────────────

class Reserva {
    protected:
        int dni;
        string nombre;
        string tipo;
        int duracion;
    public:
        Reserva(int dni, string nombre, string tipo, int duracion);
        int getdni()          { return dni; }
        string getnombre()    { return nombre; }
        string gettipo()      { return tipo; }
        int getduracion()     { return duracion; }
        virtual double getcosto() = 0;

        // (4-15) Sobrecarga operator
        friend ostream& operator<<(ostream& os, Reserva& r) {
            os << r.nombre      << " ... "
               << r.tipo        << " ... "
               << r.duracion    << " ... "
               << r.getcosto();
            return os;
        }
};

Reserva::Reserva(int dni, string nombre, string tipo, int duracion) {
    this->dni      = dni;
    this->nombre   = nombre;
    this->tipo     = tipo;
    this->duracion = duracion;
}

// ─── RESERVA ESTÁNDAR ─────────────────────────────────────────────────────────

class ReservaEstandar : public Reserva {
    public:
        ReservaEstandar(int dni, string nombre, int duracion)
            : Reserva(dni, nombre, "Estandar", duracion) {}

        double getcosto() {
            return duracion * 15000.0;
        }
};

// ─── RESERVA PREMIUM ──────────────────────────────────────────────────────────

class ReservaPremium : public Reserva {
    public:
        ReservaPremium(int dni, string nombre, int duracion)
            : Reserva(dni, nombre, "Premium", duracion) {}

        double getcosto() {
            return duracion * 30000.0 * 1.10;
        }
};

// ─── RESERVA MIXTA ────────────────────────────────────────────────────────────

class ReservaMixta : public Reserva {
    private:
        int nochesEstandar;
        int nochesPremium;
    public:
        ReservaMixta(int dni, string nombre, int nochesEstandar, int nochesPremium)
            : Reserva(dni, nombre, "Mixta", nochesEstandar + nochesPremium),
              nochesEstandar(nochesEstandar), nochesPremium(nochesPremium) {}

        double getcosto() {
            return (nochesEstandar * 15000.0) + (nochesPremium * 30000.0 * 1.10);
        }
};

// ─── CLASE GESTOR ─────────────────────────────────────────────────────────────

class Gestor {
    private:
        MiVector<Reserva*> vec_reserva;
    public:
        Gestor();

        // (3-20) Cargar reservas, calcular y mostrar
        void cargarReserva(Reserva* r) {
            vec_reserva.agregar(r);
        }

        void mostrarTodas() {
            for (int i = 0; i < vec_reserva.size(); i++)
                cout << *vec_reserva[i] << endl;
        }
};

Gestor::Gestor() {}

int main() {

    return 0;
}