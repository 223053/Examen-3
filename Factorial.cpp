/** Nombre: Leslie Lucero Franco Calleros 
 Matricula: 223053
 Descripcion: El siguiente codigo es un numero factorial, utilizando
 recursividad para realizar el proceso.
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

int main() {
    int num;
    list<Nodo> lista;

    cout << "Ingrese el numero para realizar el factorial: ";
    cin >> num;

    calcularRecursividad(num, lista);

    cout << endl<<"Factorial de " << num << ": " << lista.back().recursivo << endl;

    system("pause");
    return 0;
}

/** Función para calcular la recursividad */
void calcularRecursividad(int num, list<Nodo> &lista) {
    if (num <= 1) { 
        lista.push_back({1});
        cout << "Paso intermedio: 1" << endl; // Mostrar el primer valor
        return;
    } else {
        calcularRecursividad(num - 1, lista);
        int resultado = num * lista.back().recursivo;
        lista.push_back({resultado});
        cout << "Paso intermedio: " << resultado << endl; // Mostrar cada paso intermedio
    }
}