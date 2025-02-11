#ifndef COMPLEJOS_H
#define COMPLEJOS_H

typedef struct {
    double real;
    double imag;
} Complejo;

Complejo CrearComplejo(double re, double im);
double ParteReal(Complejo c);
double ParteImaginaria(Complejo c);
double Modulo(Complejo c);
Complejo Conjugado(Complejo c);
Complejo Sumar(Complejo c1, Complejo c2);
Complejo Restar(Complejo c1, Complejo c2);
Complejo Multiplicar(Complejo c1, Complejo c2);
Complejo Dividir(Complejo c1, Complejo c2);

#endif