#include "estructuras.h"

int main(int argc, char const *argv[]) {
    int opcion;
    int cantidadPorciones;
    int cantidadComponente;
    string nombreCombo, nuevoNombreCombo;
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
                 cin.ignore();
                 Combo *nuevoCombo = new Combo(nombreCombo, cantidadPorciones);
                 if (bs->estaCombo(nombreCombo)){
                     cout << "El nombre del combo ya está agregado." << endl << endl;
                     break;
                 }

                 while (true){
                     cout << "Nombre de componente a agregar: ";
                     getline(cin, nombreComponente);
                     if (nombreComponente == "") break;
                     cout << "Cantidad: ";
                     cin >> cantidadComponente;
                     cin.ignore();
                     cout << "Unidad de medida (vaso, lata, unidad): ";
                     getline(cin, unidadMedida);
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
            cout << "*****Modificar nombre de un combo*****" << endl << endl;
            cout << "Nombre del combo a modificar: ";
            cin.ignore();
            getline(cin, nombreCombo);
            if(bs->estaCombo(nombreCombo)){
                for(int i = 0; i < 100; i++){
                    if(bs->combos[i].nombre == nombreCombo){
                        cout << endl <<"Ingrese nuevo nombre del combo: ";
                        cin.ignore();
                        getline(cin, nuevoNombreCombo);
                        bs->combos[i].nombre = nuevoNombreCombo;
                        cout << endl << "Nombre del combo cambiado exitosamente." <<endl << endl;
                        break;
                    }
                }
            }
            else{
                cout << endl <<"El combo ingresado NO existe!!" << endl << endl;
            }
        } else if (opcion == 6){
            cout << "*****Modificar cantidad de un componente de un combo*****" << endl << endl;
            cout << "Nombre del combo: ";
            cin.ignore();
            getline(cin, nombreCombo);
            if(bs->estaCombo(nombreCombo)){
                for(int i = 0; i < 100; i++){
                    if(bs->combos[i].nombre == nombreCombo){
                        cout << endl <<"Nombre del componente: ";
                        getline(cin, nombreComponente);
                        if(bs->combos[i].estaComponente(nombreComponente)){
                            for(int i=0; i<30; i++){
                                if(bs->combos[i].componentes[i].nombre == nombreComponente){
                                    cout << endl << "Digite la nueva cantidad del componente: ";
                                    cin >> cantidadComponente;
                                    cin.ignore();
                                    bs->combos[i].componentes[i].cantidad = cantidadComponente;
                                    cout << endl << "Cantidad modificada exitosamente" << endl;
                                    break;
                                }
                            }
                            break; // Este break es para salirse del for para buscar el combo
                        }
                    }
                    else{
                        cout << endl <<"El combo NO tiene ese componente!!" << endl << endl;
                        break;
                    }
                }
            }
            else{
                cout << endl <<"El combo ingresado NO existe!!" << endl << endl;
            }
        } else if (opcion == 7){
            /* code */
        } else if (opcion == 8){
            /* code */
        } 
        else if (opcion == 9) break;
        }
}
