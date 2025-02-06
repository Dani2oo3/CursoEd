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
    return -1;
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

void ejecutarPractica2() {
    int tam = 20000;
    int array[tam];

    // Inicializar el array con números aleatorios entre 0 y 999
    for (int i = 0; i < tam; i++) {
        array[i] = rand() % 1000;  // Valores aleatorios entre 0 y 999
    }

    // Imprimir el array original
    printf("Array original:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // MEDICIÓN DEL TIEMPO PARA LA BÚSQUEDA SECUENCIAL
    int elem = 1000; // Elemento a buscar
    clock_t start = clock();
    int result = busquedaSecuencia(array, tam, elem);
    clock_t end = clock();
    double tiempoBusquedaSecuencial = (double)(end - start) / CLOCKS_PER_SEC;
    if (result != -1) {
        printf("Elemento encontrado en la posición %d con busqueda secuencial.\n", result);
    } else {
        printf("Elemento no encontrado con busqueda secuencial.\n");
    }
    printf("Tiempo de busqueda secuencial: %f segundos.\n", tiempoBusquedaSecuencial);

    // MEDICIÓN DEL TIEMPO PARA LA BÚSQUEDA BINARIA
    start = clock();
    result = busquedaBinaria(array, tam, elem);
    end = clock();
    double tiempoBusquedaBinaria = (double)(end - start) / CLOCKS_PER_SEC;
    if (result != -1) {
        printf("Elemento encontrado en la posición %d con busqueda binaria.\n", result);
    } else {
        printf("Elemento no encontrado con busqueda binaria.\n");
    }
    printf("Tiempo de busqueda binaria: %f segundos.\n", tiempoBusquedaBinaria);

    // MEDICIÓN DEL TIEMPO PARA EL ORDENAMIENTO POR BURBUJA
    start = clock();
    ordenamientoBurbuja(array, tam);  // Utilizando el algoritmo de ordenación por burbuja
    end = clock();
    double tiempoOrdenacion = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tiempo de ordenacion por burbuja: %f segundos.\n", tiempoOrdenacion);

    // MEDICIÓN DEL TIEMPO PARA EL ORDENAMIENTO POR MEZCLA
    start = clock();
    ordenamientoPorMezcla(array, tam);  // Ordenar con mezcla
    end = clock();
    double tiempoOrdenamientoMezcla = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tiempo de ordenacion por mezcla: %f segundos.\n", tiempoOrdenamientoMezcla);

    // Mostrar el array ordenado
    printf("Array ordenado:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}