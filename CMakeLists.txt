cmake_minimum_required(VERSION 3.29)
project(practicasED C)

set(CMAKE_C_STANDARD 11)

add_executable(practicasED main.c
        practica1/practica1.c
        practica2/practica2.c
        practica3/complejos/complejos.c
        practica3/circuito/circuito.c
        practica3/practica3.c
        practica4/material/bitmap.c
        practica4/mandelbrot/mandelbrot.c
        practicaListas/tiposListas/listaDoblementeEnlazada.c
        practicaListas/elemento/elemento.c
        practicaListas/tiposListas/listaEnlazada.c
        practicaListas/ejecutarPractica/practicaListas.c
        practica5/practica5/listaEnlazadaNoticia.c
        practica5/noticia/noticia.c
        practica5/practica5/listaEnlazadaNoticia.h)
