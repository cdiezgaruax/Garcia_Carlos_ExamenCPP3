cmake_minimum_required(VERSION 3.29)
project(Garcia_Carlos_ExamenCPP3)

set(CMAKE_CXX_STANDARD 14)

add_executable(original
    original/main.cpp
    original/eje/Funciones.cpp
    original/eje/Funciones.h
    original/eje/Tarea.h
)

add_executable(modificado-en-clase
    modificado/main.cpp
    modificado/Lanzador.cpp
    modificado/Lanzador.h
    modificado/tarea/Tarea.cpp
    modificado/tarea/Tarea.h
    modificado/crud/CRUD.h
    modificado/Clases/Worker.cpp
    modificado/Clases/Worker.h
    modificado/Clases/WorkerType.h
)