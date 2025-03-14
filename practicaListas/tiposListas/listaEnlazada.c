#include <stdio.h>
#include <stdlib.h>
#include "listaEnlazada.h"

/*
 * Crea una lista enlazada vacía
 * Retorna un puntero a ListaEnlazada
 */
ListaEnlazada* crearLista() {
    return NULL;
}

/*
 * Inserta un elemento al inicio de la lista
 * Recibe un puntero a puntero a ListaEnlazada y un Elemento
 */
void insertarElemento(ListaEnlazada **lista, Elemento elemento) {
    ListaEnlazada *nuevoNodo = (ListaEnlazada*)malloc(sizeof(ListaEnlazada));
    if (!nuevoNodo) {
        printf("Error al asignar memoria\n");
        return;
    }
    nuevoNodo->info = elemento;
    nuevoNodo->siguiente = *lista;
    *lista = nuevoNodo;
}

/*
 * Muestra los elementos de la lista
 * Recibe un puntero a ListaEnlazada
 */
void mostrarLista(ListaEnlazada *lista) {
    ListaEnlazada *actual = lista;
    while (actual) {
        printf("%d -> ", actual->info);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

/*
 * Libera la memoria asignada a la lista
 * Recibe un puntero a ListaEnlazada
 */
void liberarLista(ListaEnlazada *lista) {
    ListaEnlazada *actual = lista;
    while (actual) {
        ListaEnlazada *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}
