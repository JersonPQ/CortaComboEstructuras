#include <iostream>

using namespace std;

struct Componente{
    string nombre;
    string unidadMedida;
    int cantidad;

    Componente(){
        nombre = "";
        unidadMedida = "";
        cantidad = 0;
    }

    Componente(string _nombre, string _unidadMedida, int _cantidad){
        nombre = _nombre;
        unidadMedida = _unidadMedida;
        cantidad = _cantidad;
    }
};

struct Combo{
    string nombre;
    int cantidadPorciones;
    int contador;
    Componente componentes[30];

    Combo(){
        nombre = "";
        cantidadPorciones = 0;
        contador = 0;
    }

    Combo(string _nombre, int _cantidadPorciones){
        contador = 0;
        nombre = _nombre;
        cantidadPorciones = _cantidadPorciones;
    }

    void agregarComponente(Componente _componente){
        componentes[contador] = _componente;
        contador++;
    }

    bool estaComponente(string _nombreCombo){
        for (int i = 0; i < 30; i++){
            if (componentes[i].nombre == _nombreCombo){
                return true;
            }
        }

        return false;
    }
};

struct BaseDatos{
    Combo *combos = new Combo[100];
    int contador = 0;

     BaseDatos(){
         contador = 0;
     }

    void agregarCombo(Combo _combo){
        combos[contador] = _combo;
        contador++;
    }

    bool estaCombo(string _nombreCombo){
        for (int i = 0; i < 100; i++){
            if (combos[i].nombre == _nombreCombo){
                return true;
            }
        }

        return false;
    }
};
