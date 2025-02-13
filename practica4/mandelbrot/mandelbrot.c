#include <stdio.h>
#include "mandelbrot.h"
#include "../../practica3/complejos/complejos.h"
#include "../material/bitmap.h"

// Función para calcular si el número pertenece al conjunto de Mandelbrot
int PerteneceMandelbrot(Complejo c) {
    Complejo z = CrearComplejo(0.0, 0.0);
    int iteraciones = 0;

    while (Modulo(z) <= 2.0 && iteraciones < MAX_ITER) {
        z = Sumar(Multiplicar(z, z), c);
        iteraciones++;
    }

    return iteraciones;
}

// Función para dibujar el fractal y guardarlo en un archivo BMP
void DibujarMandelbrot() {
    // Crear el archivo BMP
    Bitmap mandelbrot = createBitmap("../practica4/gradiente.bmp", ANCHO, ALTO, 3);

    for (int y = 0; y < ALTO; y++) {
        for (int x = 0; x < ANCHO; x++) {
            // Mapear las coordenadas de pantalla al plano complejo
            double re = X_MIN + (x / (double)ANCHO) * (X_MAX - X_MIN);
            double im = Y_MIN + (y / (double)ALTO) * (Y_MAX - Y_MIN);
            Complejo c = CrearComplejo(re, im);
            int iter = PerteneceMandelbrot(c);

            // Calcular el color según el número de iteraciones
            unsigned char color = (iter == MAX_ITER) ? 0 : (unsigned char)(iter * 255 / MAX_ITER);

            // Usar la función putPixel para asignar el color en escala de grises
            putPixel(&mandelbrot, x, y, color);
        }
    }

    // Guardar el archivo BMP
    saveBitmap(&mandelbrot);
}

// Función para ejecutar la práctica
int ejecutarPractica4() {
    DibujarMandelbrot();
    return 0;
}
