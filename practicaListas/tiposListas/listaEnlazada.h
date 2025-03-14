#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include "../elemento/elemento.h"

typedef struct ListaEnlazada {
    Elemento info;
    struct ListaEnlazada *siguiente;
} ListaEnlazada;

ListaEnlazada* crearLista();
void insertarElemento(ListaEnlazada **lista, Elemento elemento);
void mostrarLista(ListaEnlazada *lista);
void liberarLista(ListaEnlazada *lista);

#endif // LISTA_ENLAZADA_H
