#ifndef TASK_H
#define TASK_H

#include <string>
#include <memory>
#include <vector>
#include "../Clases/Trabajador.h" // Incluye la definición de Worker y WorkerType
#include "../Clases/TrabajadorType.h" // Incluye la definición de WorkerType

class Trabajador; // Declaración anticipada para evitar dependencias circulares

class Task {
private:
    std::string name;                              // Nombre de la tarea
    int duration;                                  // Duración total de la tarea
    int remaining_time;                            // Tiempo restante para completar la tarea
    Trabajador* assigned_worker;                       // Trabajador asignado a esta tarea
    TrabajadorType worker_type;                        // Tipo de trabajador requerido para esta tarea
    std::vector<std::shared_ptr<Task>> dependencies; // Lista de dependencias (otras tareas)

public:
    // Constructores
    Task(const std::string& taskName, int taskDuration, TrabajadorType workerType,
         const std::vector<std::shared_ptr<Task>>& dependencies = {});
    Task(const std::string& taskName, int taskDuration,
         const std::vector<std::shared_ptr<Task>>& dependencies = {});

    // Métodos para el trabajador asignado
    Trabajador* getWorker() const;
    void setWorker(Trabajador* worker);

    // Función para actualizar la tarea
    void Update();

    // Verificar si la tarea está completa
    bool isCompleted() const;

    // Verificar si la tarea puede realizarse (todas las dependencias completas)
    bool can_be_done() const;

    // Obtener información sobre la tarea
    std::string getName() const;
    int getDuration() const;
    int getRemainingTime() const;
    TrabajadorType getWorkerType() const;
};

#endif //TASK_H
