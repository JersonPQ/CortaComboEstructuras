#include "estructuras.h"

int main(int argc, char const *argv[]) {
    int opcion;
    int cantidadPorciones;
    int cantidadComponente;
    string nombreCombo;
    string nombreComponente;
    string unidadMedida;
    BaseDatos *bs = new BaseDatos();
    
    while (true){
        cout << "*****MENU*****" << endl;
        cout << "1. Agregar combo" << endl;
        cout << "2. Buscar combo" << endl;
        cout << "3. Borrar combo" << endl;
        cout << "4. Imprimir todos los combos" << endl;
        cout << "5. Modificar nombre de un combo" << endl;
        cout << "6. Modificar cantidad de un componente de un combo" << endl;
        cout << "7. Agregar un componente a un combo" << endl;
        cout << "8. Calcular para porciones" << endl;
        cout << "9. Salir" << endl << endl;

        cout << "Digite la opción: ";
        cin >> opcion;
        cout << endl << endl;

        if (opcion == 1){
             while (true){
                 cout << "*****Agregar Combo*****" << endl << endl;
                 cout << "Nombre del combo: ";
                 cin.ignore();
                 getline(cin, nombreCombo);
                 cout << "Cantidad de porciones: ";
                 cin >> cantidadPorciones;
                 Combo *nuevoCombo = new Combo(nombreCombo, cantidadPorciones);
                 if (bs->estaCombo(nombreCombo)){
                     cout << "El nombre del combo ya está agregado." << endl << endl;
                     break;
                 }

                 while (true){
                     cout << "Nombre de componente a agregar: ";
                     cin.ignore();
                     getline(cin, nombreComponente);
                     if (nombreComponente == "") break;

                     cout << "Cantidad: ";
                     cin >> cantidadComponente;
                     cout << "Unidad de medida (vaso, lata, unidad): ";
                     cin >> unidadMedida;
                     Componente *nuevoComponente = new Componente(nombreComponente, unidadMedida, cantidadComponente);
                     if (nuevoCombo->estaComponente(nombreComponente)){
                         cout << "Nombre de componente ya ha sido agregado." << endl << endl;
                     } else {
                         nuevoCombo->agregarComponente(*nuevoComponente);
                     }
                 }

                 bs->agregarCombo(*nuevoCombo);
                 break;
             }
            
        } 
        else if (opcion == 2){
            /* code */
        } else if (opcion == 3){
            /* code */
        } else if (opcion == 4){
            /* code */
        } else if (opcion == 5){
            /* code */
        } else if (opcion == 6){
            /* code */
        } else if (opcion == 7){
            /* code */
        } else if (opcion == 8){
            /* code */
        } 
        else if (opcion == 9) break;
    }
    
}
