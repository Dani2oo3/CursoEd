#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del elemento
typedef struct Elemento {
    int info;
} Elemento;

// Funciones para manejar los elementos
Elemento* crearElemento(int valor);
void mostrarElemento(const Elemento* e);
void liberarElemento(Elemento* e);

#endif // ELEMENTO_H