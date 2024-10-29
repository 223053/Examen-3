/** 
 Nombre: Leslie Lucero Franco Calleros 
 Matrícula: 223053
 Descripción: El siguiente código calcula el factorial de un número utilizando recursividad 
 para realizar el proceso y también implementa una simulación de cajero automático para 
 consultar saldo, retirar efectivo, y mostrar el saldo.
*/

#include <iostream>
#include <windows.h>
#include <list>

using namespace std;

/** Estructura nodo para englobar más de un dato en el nodo de la lista */
struct Nodo {
    int recursivo;
};

/** Prototipos */
void calcularRecursividad(int, list<Nodo> &);
void cajeroAutomatico();

int main() {
    int opcion;
    /**Menu de opciones para elegir entre funcion de cajero y factorial */
    do {
        cout << endl<<"*** Menu Principal ***"
        << endl << "1. Calcular Factorial" 
        << endl << "2. Cajero Automatico" 
        << endl << "0. Salir" 
        << endl << "Ingresa tu opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int num;
                list<Nodo> lista;

                cout << "Ingrese el numero para realizar el factorial: ";
                cin >> num;

                calcularRecursividad(num, lista);

                cout << endl << "Factorial de " << num << ": " << lista.back().recursivo << endl;
                break;
            }
            case 2:
                cajeroAutomatico();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }

        system("pause");
    } while (opcion != 0);

    return 0;
}

/** Función para calcular la recursividad (factorial) */
void calcularRecursividad(int num, list<Nodo> &lista) {
    if (num <= 1) { 
        lista.push_back({1});
        cout << "Paso intermedio: 1" << endl;
        return;
    } else {
        calcularRecursividad(num - 1, lista);
        int resultado = num * lista.back().recursivo;
        lista.push_back({resultado});
        cout << "Paso intermedio: " << resultado << endl;
    }
}

/** Función de cajero automatico */
void cajeroAutomatico() {
    int saldo = 20000;
    int opcion, retiro;

    do {/**Menu de cajero automatico */
        cout << endl <<"*** Cajero Automatico ***" 
        << endl << "1. Consultar saldo" 
        << endl << "2. Retirar efectivo" 
        << endl << "3. Mostrar saldo" 
        << endl << "0. Salir" 
        << endl << "Ingresa tu opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Su saldo actual es: $" << saldo << endl;
                break;
            case 2:
                cout << "Ingrese el monto a retirar: $";
                cin >> retiro;/**Si el saldo es insuficiente pasara a la opcion de regresar*/ 
                if (retiro > saldo) {
                    cout << "Saldo insuficiente para realizar el retiro." << endl;
                } else {
                    saldo -= retiro;
                    cout << "Retiro exitoso. Monto retirado: $" << retiro << endl;
                }
                break;
            case 3:
                cout << "Saldo disponible: $" << saldo << endl;
                break;
            case 0:
                cout << "Saliendo del cajero automatico..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 0);
}
