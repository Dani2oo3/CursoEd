#include "practicaListas.h"

void ejecutarPracticaListas() {
    ListaEnlazada *lista = crearLista();
    Elemento e1 = {10};
    Elemento e2 = {20};
    insertarElemento(&lista, e1);
    insertarElemento(&lista, e2);
    mostrarLista(lista);
    liberarLista(lista);
}

void ejecutarPracticaListasDobles() {
    ListaDoblementeEnlazada *lista = crearListaDoble();
    Elemento e1 = {30};
    Elemento e2 = {40};
    insertarElementoDoble(&lista, e1);
    insertarElementoDoble(&lista, e2);
    mostrarListaDoble(lista);
    liberarListaDoble(lista);
}