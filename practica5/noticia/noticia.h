#ifndef NOTICIA_H
#define NOTICIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura de la noticia
typedef struct Noticia {
    char *titulo;
    char *fecha;
    char *medio;
    int visitas;
} Noticia;

// Funciones para manejar los elementos
Noticia* crearNoticia(const char* titulo, const char* fecha, const char* medio, int visitas);
void mostrarNoticia(const Noticia* e);
void liberarNoticia(Noticia* e);

#endif //NOTICIA_H
