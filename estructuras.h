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

    void imprimirComponente(){
        cout << "\tNombre componente: " << nombre << endl;
        cout << "\tCantidad: " << cantidad << endl;
        cout << "\tUnidad de medida (vaso, lata, unidad): " << unidadMedida << endl << endl;
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

    void imprimirCombo(){
        cout << endl << "Nombre: " << nombre << endl;
        cout << "Porciones: " << cantidadPorciones << endl;
        for (int i = 0; i < contador; ++i) {
            componentes[i].imprimirComponente();
        }

        cout << endl << endl;
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

    void borrarCombo(string _nombreCombo){
         int indiceCoincidencia = 100;
         for (int i = 0; i < 100; i++){
             if (i > indiceCoincidencia) {
                 // elementos después del elemento borrado son movidos una posición a la izquierda para no tener un
                 // espacio vacío
                 combos[i - 1] = combos[i];
             } else if (combos[i].nombre == _nombreCombo){
                 // variable toma el valor del índice del elemento a borrar
                 indiceCoincidencia = i;
                 combos[i] = Combo();
                 contador--;
             }
         }
    }

    void imprimirCombos(){
        for (int i = 0; i < contador; ++i) {
            combos[i].imprimirCombo();
        }
     }
};
