#include "practica1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay_microsecond() {
    clock_t start = clock();
    while (clock() < start + (CLOCKS_PER_SEC / 1000000)); // Espera 1 microsegundo
}

void calcularEspacioStack(int num) {
    if (num > 0) {
        int almacen[20000]; // ocupa 80000 bytes 20000 * 4 bytes
        calcularEspacioStack(num - 1);
    }
}

void calcularEspacioHeap(int numHeap) {
    int *almacen = (int *)malloc(20000 * sizeof(int)); // Reserva en el heap (80 KB por bloque)

    if (numHeap > 0) {
        delay_microsecond(); // Un microsegundo
        calcularEspacioHeap(numHeap - 1); // Llamada recursiva
    }

    free(almacen); // Liberar la memoria
}

void ejecutarPractica1() {
    calcularEspacioStack(24);
    /*
    total de bytes del stack 24 repes: 80000 * 24 = 1.920.000 bytes = 1.920 KB = 1.92 MB
    total de bytes del stack 25 repes (fallo): 80000 * 25 = 2.000.000 bytes = 2.000 KB = 2 MB
    */

    calcularEspacioHeap(32460);
    /*
    total de bytes del heap 32470 repes: 80000 * 32470 = 2.597.600.000 bytes = 2.597.600 KB = 2.536.000 MB = 2,536 GB
    total de bytes del heap 32471 repes (fallo): 80000 * 32471 = 2.597.680.000 bytes = 2.597.680 KB = 2.536.080 MB = 2,536 GB
    */
}
