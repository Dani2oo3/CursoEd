#ifndef PRACTICA5_H
#define PRACTICA5_H

#include <stdio.h>
#include <stdlib.h>
#include "../noticia/noticia.h"

typedef struct Nodo {
    Noticia info;
    struct Nodo* sig;
}tNodo;

typedef tNodo* tLista;

void construir(tLista* pLista, Noticia elem);
void asisnar(tLista* pLista, Noticia elem);
void insertarElemento(tLista* lista, Noticia elem);
void mostrarLista(tLista* lista); //No se que va dentro de los parentesis, si lista, *lista, **lista o &lista
void liberarLista(tLista* lista); //igual

#endif //PRACTICA5_H