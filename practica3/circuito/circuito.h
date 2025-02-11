#ifndef CIRCUITO_H
#define CIRCUITO_H
#include "../complejos/complejos.h"

Complejo ImpedanciaR(double R);
Complejo ImpedanciaC(double C, double w);
Complejo ImpedanciaL(double L, double w);
Complejo ImpedanciaTotal(Complejo Zr, Complejo Zc, Complejo Zl);
double FrecuenciaAngular(double nu);
Complejo Intensidad(Complejo V, Complejo Z);
Complejo CaidaPotencial(Complejo I, Complejo Z);

#endif // CIRCUITO_H