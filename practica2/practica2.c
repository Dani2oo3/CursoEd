#include "practica2.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int busquedaSecuencia(int *array, int tam, int elem) {
    int i = 0;
    while (i < tam) {
        if (array[i] == elem) {
            return i;
        }
        i++;
    }
    return -1;
}

int busquedaBinaria(int *array, int tam, int elem) {
    int inicio = 0;
    int fin = tam - 1;
    int medio;
    while (inicio <= fin) {
        medio = (inicio + fin) / 2;
        if (array[medio] == elem) {
            return medio;
        }
        if (array[medio] < elem) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1; // Elemento no encontrado
}

int ordenamientoBurbuja (int * array, int tam) {
    int aux;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1; j++) {
            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    return 0;

}

void mezclar(int *array, int *aux, int inicio, int mitad, int fin) {
    int i = inicio;
    int j = mitad + 1;
    int k = inicio;

    while (i <= mitad && j <= fin) {
        if (array[i] <= array[j]) {
            aux[k] = array[i];
            i++;
        } else {
            aux[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mitad) {
        aux[k] = array[i];
        i++;
        k++;
    }

    while (j <= fin) {
        aux[k] = array[j];
        j++;
        k++;
    }

    for (i = inicio; i <= fin; i++) {
        array[i] = aux[i];
    }
}

int ordenamientoPorMezcla(int *array, int tam) {
    int *aux = (int *)malloc(tam * sizeof(int));  // Crear un array auxiliar
    if (!aux) {
        return -1;  // Error de asignación de memoria
    }

    for (int paso = 1; paso < tam; paso *= 2) {
        for (int i = 0; i < tam - paso; i += 2 * paso) {
            int inicio = i;
            int mitad = i + paso - 1;
            int fin = (i + 2 * paso - 1 < tam) ? i + 2 * paso - 1 : tam - 1;
            mezclar(array, aux, inicio, mitad, fin);
        }
    }

    free(aux);  // Liberar memoria
    return 0;
}

// Funciones para ejecutar la práctica 2

void pintarArrayOriginal(int *array, int tam) {
    printf("Array original:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void pintarArrayOrdenado(int *array, int tam) {
    printf("Array ordenado:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void medicionBusquedaSecuencial(int *array, int tam) {
    int elemSec = 1000; // Elemento a buscar
    clock_t startSec = clock();
    int resultSec = busquedaSecuencia(array, tam, elemSec);
    clock_t endSec = clock();
    double tiempoBusquedaSecuencial = (double)(endSec - startSec) / CLOCKS_PER_SEC;
    if (resultSec != -1) {
        printf("Elemento encontrado en la posición %d con búsqueda secuencial.\n", resultSec);
    } else {
        printf("Elemento no encontrado con búsqueda secuencial.\n");
    }
    printf("Tiempo de búsqueda secuencial: %f segundos.\n", tiempoBusquedaSecuencial);
}

void medicionBusquedaBinaria(int *array, int tam) {
    int elemBin = 1000;
    clock_t startBin = clock();
    int resultBin = busquedaBinaria(array, tam, elemBin);
    clock_t endBin = clock();
    double tiempoBusquedaBinaria = (double)(endBin - startBin) / CLOCKS_PER_SEC;
    if (resultBin != -1) {
        printf("Elemento encontrado en la posición %d con búsqueda binaria.\n", resultBin);
    } else {
        printf("Elemento no encontrado con búsqueda binaria.\n");
    }
    printf("Tiempo de búsqueda binaria: %f segundos.\n", tiempoBusquedaBinaria);
}

void ordenarBurbuja(int *array, int tam) {
    clock_t startBurbuja = clock();
    ordenamientoBurbuja(array, tam);
    clock_t endBurbuja = clock();
    double tiempoOrdenacionBurbuja = (double)(endBurbuja - startBurbuja) / CLOCKS_PER_SEC;
    printf("Tiempo de ordenación por burbuja: %f segundos.\n", tiempoOrdenacionBurbuja);
}

void ordenarMezcla(int *array, int tam) {
    clock_t startMezcla = clock();
    ordenamientoPorMezcla(array, tam);
    clock_t endMezcla = clock();
    double tiempoOrdenamientoMezcla = (double)(endMezcla - startMezcla) / CLOCKS_PER_SEC;
    printf("Tiempo de ordenación por mezcla: %f segundos.\n", tiempoOrdenamientoMezcla);
}

void ejecutarPractica2() {
    int tam = 100000;
    int array[tam];

    // Inicializar el array con números aleatorios entre 0 y 999
    for (int i = 0; i < tam; i++) {
        array[i] = rand() % 1000;
    }

    pintarArrayOriginal(array, tam);
    medicionBusquedaSecuencial(array, tam);
    medicionBusquedaBinaria(array, tam);
    ordenarBurbuja(array, tam);
    ordenarMezcla(array, tam);
    pintarArrayOrdenado(array, tam);
}