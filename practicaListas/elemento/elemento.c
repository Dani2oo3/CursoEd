#include "elemento.h"

/*
 * Implementación de las funciones de la biblioteca elemento
 * retorna un puntero a un nuevo elemento con el valor dado
 */
Elemento* crearElemento(int valor) {
    Elemento* nuevo = (Elemento*)malloc(sizeof(Elemento)); // Reserva memoria para el nuevo elemento
    if (nuevo != NULL) {
        nuevo->info = valor;
    }
    return nuevo;
}

/*
 * Muestra el valor de un elemento
 */
void mostrarElemento(const Elemento* e) {
    if (e != NULL) {
        printf("Elemento: %d\n", e->info);
    }
}

/*
 * Libera la memoria reservada para un elemento
 */
void liberarElemento(Elemento* e) {
    free(e);
}

