#ifndef PRACTICA1_H
#define PRACTICA1_H

/*

Se pretende comprobar las limitaciones de los diferentes espacios de memoria principal (montículo/heap
y pila/stack) mediante el uso de subprogramas recursivos que reserven en cada llamada un array de
grandes dimensiones hasta que se desborde dicho espacio de memoria. Queremos conocer, de manera
aproximada, cuánto espacio disponemos en cada una de las zonas de memoria.

 */

void delay_microsecond();
void calcularEspacioStack(int num);
void calcularEspacioHeap(int numHeap);
void ejecutarPractica1();

#endif
