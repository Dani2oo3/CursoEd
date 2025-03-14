#include <stdio.h>
#include <stdlib.h>
#include "listaDoblementeEnlazada.h"

/*
 * Implementación de las funciones de la lista doblemente enlazada
 */
ListaDoblementeEnlazada* crearListaDoble() {
    return NULL;
}

/*
 * Inserta un elemento al final de la lista doblemente enlazada
 * @param lista: lista doblemente enlazada
 * @param elemento: elemento a insertar
 * @return lista doblemente enlazada con el nuevo elemento
 */
void insertarElementoDoble(ListaDoblementeEnlazada **lista, Elemento elemento) {
    ListaDoblementeEnlazada *nuevoNodo = (ListaDoblementeEnlazada*)malloc(sizeof(ListaDoblementeEnlazada));
    if (!nuevoNodo) {
        printf("Error al asignar memoria\n");
        return;
    }
    nuevoNodo->info = elemento;
    nuevoNodo->siguiente = *lista;
    nuevoNodo->anterior = NULL;

    if (*lista) {
        (*lista)->anterior = nuevoNodo;
    }

    *lista = nuevoNodo;
}

/*
 * mostrar los elementos de la lista doblemente enlazada
 * @param lista: lista doblemente enlazada
 * @param elemento: elemento a eliminar
 * @return lista doblemente enlazada sin el elemento
 */
void mostrarListaDoble(ListaDoblementeEnlazada *lista) {
    ListaDoblementeEnlazada *actual = lista;
    while (actual) {
        printf("%d <-> ", actual->info);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

/*
 * Elimina elemento tras elemento de la lista doblemente enlazada
 * @param lista: lista doblemente enlazada
 * @param elemento: elemento a eliminar
 * @return lista doblemente enlazada sin el elemento
 */
void liberarListaDoble(ListaDoblementeEnlazada *lista) {
    ListaDoblementeEnlazada *actual = lista;
    while (actual) {
        ListaDoblementeEnlazada *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}
