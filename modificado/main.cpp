#include <iostream>
#include <vector>
#include <memory>
#include "crud/crud.h"
#include "tarea/Tarea.h"
#include "Clases/Trabajador.h"
#include "Clases/TrabajadorType.h"

int main() {
    std::vector<std::shared_ptr<Task>> taskDB;
    std::vector<std::shared_ptr<Trabajador>> workerDB;

    CRUD<std::shared_ptr<Task>> taskCRUD(taskDB);
    CRUD<std::shared_ptr<Trabajador>> workerCRUD(workerDB);

    auto task1 = std::make_shared<Task>("Planificacion", 5, TrabajadorType::CEO);
    auto task2 = std::make_shared<Task>("Marketing", 3, TrabajadorType::AGENCY);
    taskCRUD.crear(task1);
    taskCRUD.crear(task2);

    auto worker1 = std::make_shared<Trabajador>(TrabajadorType::CEO);
    auto worker2 = std::make_shared<Trabajador>(TrabajadorType::AGENCY);
    workerCRUD.crear(worker1);
    workerCRUD.crear(worker2);

    auto tasks = taskCRUD.leerTodos();
    std::cout << "\n=== Lista de Tareas ===\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i << ": " << tasks[i]->getName() << "\n";
    }

    auto workers = workerCRUD.leerTodos();
    std::cout << "\n=== Lista de Trabajadores ===\n";
    for (size_t i = 0; i < workers.size(); ++i) {
        std::cout << i << ": " << workers[i]->get_type() << "\n";
    }

    return 0;
}