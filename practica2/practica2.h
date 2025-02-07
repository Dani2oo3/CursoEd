#ifndef PRACTICA2_H
#define PRACTICA2_H

/*

En esta práctica se desea evaluar el coste computacional de diversos algoritmos midiendo
tiempos de ejecución para diferentes tamaños de problema.
Para ello será necesario hacer uso de la librería en C time.h, la cual contiene diferentes tipos
y funciones que nos permitirán manejar tiempos y fechas. Para utilizar una librería en un
programa principal (u otra librería) basta añadir “#include <time.h>” al inicio del módulo
o programa.

1) Búsqueda secuencial (𝒪𝒪(n)): itera a lo largo del array hasta encontrar el elemento
que se busca. En el peor de los casos nunca lo encuentra:

2) Busqueda binaria (𝒪𝒪(log n)): en un array previamente ordenado busca un elemento
comenzando por la posición central del array y evaluando si se ha encontrado, si no,
sigue buscando en la mitad restante que interese (mitad mayor o mitad menor). En
el peor de los casos nunca lo encuentra.

3) Ordenación directa (𝒪𝒪(n2)): se realiza mediante 2 bucles (ordenación por intercambio
directo, inserción directa, etc.), por ejemplo haciendo N pasadas de intercambios entre
elementos vecinos (siendo N el tamaño del array).

4) Ordenación por mezcla (𝒪𝒪(𝑛𝑛 log 𝑛𝑛)): algoritmo multipasada. En la primera pasada
se ordena un elemento con su respectivo vecino (longitud 1) “recorriendo ambas
posiciones por separado” (elementos en posiciones i e i+1, siendo i mod 2 = 0,
ordenando 2 elementos entre sí), en la segunda pasada el array está ordenado por
parejas y se ordenan dobles parejas mediante 2 recorridos de 2 elementos (longitud
2, ordena 4 elementos entre sí), en la siguiente pasada igual con 2 recorridos sobre 4
elementos (longitud 4, ordenando 8 elementos entre sí), y así sucesivamente hasta terminar
con 2 recorridos de cada mitad de elementos del array (longitud N/2) para
ordenar todos los valores.

 */

// Funciones de las busquedas y ordenamientos
int busquedaSecuencia (int * array, int tam, int elem);
int busquedaBinaria (int * array, int tam, int elem);
int ordenamientoBurbuja (int * array, int tam);
void mezclar(int *array, int *aux, int inicio, int mitad, int fin);
int ordenamientoPorMezcla (int * array, int tam);

// Funciones para ejecutar la práctica 2
void pintarArrayOriginal(int *array, int tam);
void pintarArrayOrdenado(int *array, int tam);
void medicionBusquedaSecuencial(int *array, int tam);
void medicionBusquedaBinaria(int *array, int tam);
void ordenarBurbuja(int *array, int tam);
void ordenarPorMezcla(int *array, int tam);

void ejecutarPractica2();

#endif
