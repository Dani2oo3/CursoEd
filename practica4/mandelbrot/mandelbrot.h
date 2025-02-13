#ifndef MANDELBROT_H
#define MANDELBROT_H

#include "../../practica3/complejos/complejos.h"

// Parámetros del fractal
#define MAX_ITER 64  // Máximo número de iteraciones
#define X_MIN -2.0   // Mínimo en el eje real
#define X_MAX 1.0    // Máximo en el eje real
#define Y_MIN -1.5   // Mínimo en el eje imaginario
#define Y_MAX 1.5    // Máximo en el eje imaginario

// Tamaño de la cuadrícula
#define ANCHO 640
#define ALTO 480

// Funciones para generar el fractal
int PerteneceMandelbrot(Complejo c);
void DibujarMandelbrot();
int ejecutarPractica4();

#endif
