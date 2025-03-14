#include "noticia.h"

/*
 * Implementación de las funciones de la biblioteca noticia
 * retorna un puntero a una nueva noticia con sus datos
 */
Noticia* crearNoticia(const char* titulo, const char* fecha, const char* medio, int visitas) {
    Noticia* nuevo = (Noticia*)malloc(sizeof(Noticia));

    // Creamos la noticia con los datos dados
    if (nuevo != NULL) {
        nuevo->titulo = (char*)malloc(strlen(titulo) + 1);
        nuevo->fecha = (char*)malloc(strlen(fecha) + 1);
        nuevo->medio = (char*)malloc(strlen(medio) + 1);

        if (nuevo->titulo != NULL && nuevo->fecha != NULL && nuevo->medio != NULL) {
            strcpy(nuevo->titulo, titulo);
            strcpy(nuevo->fecha, fecha);
            strcpy(nuevo->medio, medio);
            nuevo->visitas = visitas;
        } else {
            // Si no se pudieron reservar memoria para los datos, liberamos la memoria reservada para la noticia
            liberarNoticia(nuevo);
            nuevo = NULL;
        }
    }
}

void mostrarNoticia(const Noticia* e) {
    printf("Titulo: %s\n", e->titulo);
    printf("Fecha: %s\n", e->fecha);
    printf("Medio: %s\n", e->medio);
    printf("Visitas: %d\n", e->visitas);
}

void liberarNoticia(Noticia* e) {
    if (e != NULL) {
        if (e->titulo != NULL) {
            free(e->titulo);
        }
        if (e->fecha != NULL) {
            free(e->fecha);
        }
        if (e->medio != NULL) {
            free(e->medio);
        }
        free(e);
    }
}