#ifndef LISTA_DOBLEMENTE_ENLAZADA_H
#define LISTA_DOBLEMENTE_ENLAZADA_H

#include "../elemento/elemento.h"

typedef struct ListaDoblementeEnlazada { //TODO, cambiar ** por un typdef a puntero tNodo
    Elemento info;
    struct ListaDoblementeEnlazada *siguiente;
    struct ListaDoblementeEnlazada *anterior;
} ListaDoblementeEnlazada;

ListaDoblementeEnlazada* crearListaDoble();
void insertarElementoDoble(ListaDoblementeEnlazada **lista, Elemento elemento);
void mostrarListaDoble(ListaDoblementeEnlazada *lista);
void liberarListaDoble(ListaDoblementeEnlazada *lista);

#endif // LISTA_DOBLEMENTE_ENLAZADA_H
