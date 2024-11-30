#include "Funciones.h"
#include <queue>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

bool sePuedeCompletarEnTiempo(const vector<Tarea>& tareas, int numPersonas, int tiempoMaximo) {
    unordered_map<char, int> gradoEntrada;
    unordered_map<char, vector<char>> listaAdyacencia;
    unordered_map<char, int> duracionTarea;

    inicializarMapas(tareas, gradoEntrada, listaAdyacencia, duracionTarea);

    queue<char> cola;
    for (const auto& tarea : tareas) {
        if (gradoEntrada[tarea.id] == 0) {
            cola.push(tarea.id);
        }
    }

    vector<int> tiempoPersona(numPersonas, 0);
    while (!cola.empty()) {
        char actual = cola.front();
        cola.pop();

        int personaMin = min_element(tiempoPersona.begin(), tiempoPersona.end()) - tiempoPersona.begin();
        tiempoPersona[personaMin] += duracionTarea[actual];

        for (const auto& vecino : listaAdyacencia[actual]) {
            gradoEntrada[vecino]--;
            if (gradoEntrada[vecino] == 0) {
                cola.push(vecino);
            }
        }
    }

    return *max_element(tiempoPersona.begin(), tiempoPersona.end()) <= tiempoMaximo;
}

void inicializarMapas(const vector<Tarea>& tareas, unordered_map<char, int>& gradoEntrada, unordered_map<char, vector<char>>& listaAdyacencia, unordered_map<char, int>& duracionTarea) {
    for (const auto& tarea : tareas) {
        gradoEntrada[tarea.id] = 0;
        duracionTarea[tarea.id] = tarea.duracion;
    }

    for (const auto& tarea : tareas) {
        for (const auto& dep : tarea.dependencias) {
            listaAdyacencia[dep].push_back(tarea.id);
            gradoEntrada[tarea.id]++;
        }
    }
}

void calcularAsignaciones(const vector<Tarea>& tareas, int numPersonas, unordered_map<char, int>& asignacionTarea, unordered_map<char, int>& inicioTarea) {
    unordered_map<char, int> gradoEntrada;
    unordered_map<char, vector<char>> listaAdyacencia;
    unordered_map<char, int> duracionTarea;

    inicializarMapas(tareas, gradoEntrada, listaAdyacencia, duracionTarea);

    queue<char> cola;
    for (const auto& tarea : tareas) {
        if (gradoEntrada[tarea.id] == 0) {
            cola.push(tarea.id);
        }
    }

    vector<int> tiempoPersona(numPersonas, 0);
    while (!cola.empty()) {
        char actual = cola.front();
        cola.pop();

        int personaMin = min_element(tiempoPersona.begin(), tiempoPersona.end()) - tiempoPersona.begin();
        inicioTarea[actual] = tiempoPersona[personaMin];
        tiempoPersona[personaMin] += duracionTarea[actual];
        asignacionTarea[actual] = personaMin;

        for (const auto& vecino : listaAdyacencia[actual]) {
            gradoEntrada[vecino]--;
            if (gradoEntrada[vecino] == 0) {
                cola.push(vecino);
            }
        }
    }
}

void imprimirResultados(const vector<Tarea>& tareas, int numPersonas, const unordered_map<char, int>& asignacionTarea, const unordered_map<char, int>& inicioTarea, int horaInicio, int minutoInicio) {
    for (int i = 0; i < numPersonas; ++i) {
        cout << "Persona " << i + 1 << ":" << endl;
        cout << left << setw(10) << "Hora" << setw(10) << "Tarea" << setw(10) << "Duracion" << endl;
        cout << "----------------------------------------" << endl;
        for (const auto& tarea : tareas) {
            if (asignacionTarea.at(tarea.id) == i) {
                int horaTarea = horaInicio + (inicioTarea.at(tarea.id) + minutoInicio) / 60;
                int minutoTarea = (inicioTarea.at(tarea.id) + minutoInicio) % 60;
                cout << setw(2) << setfill('0') << horaTarea << ":"
                     << setw(2) << setfill('0') << minutoTarea << setfill(' ') << "    "
                     << tarea.id << "    "
                     << tarea.duracion << " min" << endl;
            }
        }
        cout << endl;
    }

    cout << "Tabla de tareas por hora:" << endl;
    cout << left << setw(10) << "Hora" << setw(10) << "Tarea" << setw(10) << "Persona" << setw(10) << "Duracion" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int t = 0; t <= 100; ++t) {
        for (const auto& tarea : tareas) {
            if (inicioTarea.at(tarea.id) == t) {
                int horaTarea = horaInicio + (t + minutoInicio) / 60;
                int minutoTarea = (t + minutoInicio) % 60;
                cout << setw(2) << setfill('0') << horaTarea << ":"
                     << setw(2) << setfill('0') << minutoTarea << setfill(' ') << "    "
                     << tarea.id << "    "
                     << asignacionTarea.at(tarea.id) + 1 << "    "
                     << tarea.duracion << " min" << endl;
            }
        }
    }
}