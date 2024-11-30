#include "eje/Funciones.h"
#include "eje/Tarea.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<Tarea> tareas = {
        {'A', 20, {}},
        {'B', 5, {}},
        {'C', 40, {'B'}},
        {'D', 10, {}},
        {'E', 5, {'A'}},
        {'F', 10, {'D', 'E'}},
        {'G', 20, {'C'}},
        {'H', 25, {'G'}},
        {'I', 35, {}},
        {'J', 25, {'I'}},
        {'K', 15, {'J'}},
        {'L', 5, {'K'}},
        {'M', 25, {'H'}}
    };

    int numPersonas = 1;
    while (!sePuedeCompletarEnTiempo(tareas, numPersonas, 100)) {
        numPersonas++;
    }

    cout << "Numero minimo de personas necesarias: " << numPersonas << endl;

    unordered_map<char, int> asignacionTarea;
    unordered_map<char, int> inicioTarea;
    calcularAsignaciones(tareas, numPersonas, asignacionTarea, inicioTarea);

    int horaFinal = 19;
    int minutoFinal = 30;
    int minutosTotales = horaFinal * 60 + minutoFinal - 100;
    int horaInicio = minutosTotales / 60;
    int minutoInicio = minutosTotales % 60;

    imprimirResultados(tareas, numPersonas, asignacionTarea, inicioTarea, horaInicio, minutoInicio);

    return 0;
}