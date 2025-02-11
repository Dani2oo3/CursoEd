cmake_minimum_required(VERSION 3.29)
project(practicasED C)

set(CMAKE_C_STANDARD 11)

add_executable(practicasED main.c
        practica1/practica1.c
        practica2/practica2.c
        practica3/complejos/complejos.c
        practica3/circuito/circuito.c
        practica3/practica3.c)
