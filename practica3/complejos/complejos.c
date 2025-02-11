#include "complejos.h"
#include <math.h>

Complejo CrearComplejo(double re, double im) {
    Complejo c = {re, im};
    return c;
}

double ParteReal(Complejo c) {
    return c.real;
}

double ParteImaginaria(Complejo c) {
    return c.imag;
}

double Modulo(Complejo c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

Complejo Conjugado(Complejo c) {
    return CrearComplejo(c.real, -c.imag);
}

Complejo Sumar(Complejo c1, Complejo c2) {
    return CrearComplejo(c1.real + c2.real, c1.imag + c2.imag);
}

Complejo Restar(Complejo c1, Complejo c2) {
    return CrearComplejo(c1.real - c2.real, c1.imag - c2.imag);
}

Complejo Multiplicar(Complejo c1, Complejo c2) {
    return CrearComplejo(c1.real * c2.real - c1.imag * c2.imag,
                          c1.real * c2.imag + c1.imag * c2.real);
}

Complejo Dividir(Complejo c1, Complejo c2) {
    double denom = c2.real * c2.real + c2.imag * c2.imag;
    return CrearComplejo((c1.real * c2.real + c1.imag * c2.imag) / denom,
                          (c1.imag * c2.real - c1.real * c2.imag) / denom);
}