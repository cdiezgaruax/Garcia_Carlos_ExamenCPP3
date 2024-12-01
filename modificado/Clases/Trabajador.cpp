#include "Trabajador.h"
#include <iostream>

// Constructor básico
Trabajador::Trabajador(TrabajadorType workerType)
    : type(workerType), currentTask(nullptr), specific_task(false) {}

// Constructor con propiedad specific_task
Trabajador::Trabajador(TrabajadorType workerType, bool onlySpecificTask)
    : type(workerType), currentTask(nullptr), specific_task(onlySpecificTask) {}

// Obtener el tipo del trabajador
TrabajadorType Trabajador::getType() const {
    return type;
}

// Obtener el estado del trabajador (activo si tiene una tarea asignada)
bool Trabajador::getState() const {
    return currentTask != nullptr;
}

// Asignar una tarea al trabajador
bool Trabajador::assignTask(const std::shared_ptr<Task>& task) {
    if (!task) {
        std::cerr << "Error: Task cannot be null." << std::endl;

        return false;
    }

    if (task->getWorkerType() != type) {
        //std::cerr << "Error: Worker type does not match task requirements." << std::endl;

        return false;
    }

    if (getState()) {
        std::cerr << "Error: Worker already has a task assigned." << std::endl;

        return false;
    }

    currentTask = task;
    task->setWorker(this);
    return true;
}

// Actualizar el estado del trabajador (implementación futura)
void Trabajador::Update() {
    // Este método se implementará en el futuro según los requisitos.

    if (currentTask) {
        currentTask->Update();
    }

    if (currentTask && currentTask->isCompleted()) {
        currentTask = nullptr;
    }

}

// Mostrar información del trabajador
void Trabajador::displayWorkerInfo() const {
    std::cout << "Worker Type: ";
    switch (type) {
        case TrabajadorType::CEO: std::cout << "CEO"; break;
        case TrabajadorType::AGENCY: std::cout << "AGENCY"; break;
        case TrabajadorType::GENERIC: std::cout << "GENERIC"; break;
    }
    std::cout << std::endl;

    std::cout << "State: " << (getState() ? "Active" : "Inactive") << std::endl;

    std::cout << "Specific Task Only: " << (specific_task ? "Yes" : "No") << std::endl;

    if (currentTask) {
        std::cout << "Current Task: " << currentTask->getName() << std::endl;
    } else {
        std::cout << "No current task assigned." << std::endl;
    }
}

std::string Trabajador::get_type() const {
    switch (type) {
        case TrabajadorType::CEO: return "CEO";
        case TrabajadorType::AGENCY: return "AGENCY";
        case TrabajadorType::GENERIC: return "GENERIC";
        default: return "UNKNOWN";
    }
}