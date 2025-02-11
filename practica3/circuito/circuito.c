#include "circuito.h"
#include <math.h>

Complejo ImpedanciaR(double R) {
    return CrearComplejo(R, 0);
}

Complejo ImpedanciaC(double C, double w) {
    return CrearComplejo(0, -1 / (w * C));
}

Complejo ImpedanciaL(double L, double w) {
    return CrearComplejo(0, w * L);
}

Complejo ImpedanciaTotal(Complejo Zr, Complejo Zc, Complejo Zl) {
    return Sumar(Zr, Sumar(Zc, Zl));
}

double FrecuenciaAngular(double nu) {
    return 2 * M_PI * nu;
}

Complejo Intensidad(Complejo V, Complejo Z) {
    return Dividir(V, Z);
}

Complejo CaidaPotencial(Complejo I, Complejo Z) {
    return Multiplicar(I, Z);
}