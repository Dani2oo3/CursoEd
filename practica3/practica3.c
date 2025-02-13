#include "practica3.h"
#include "circuito/circuito.h"
#include "complejos/complejos.h"
#include <stdio.h>

void ejecutarPractica3() {
    /*
    *Dado un circuito RCL en serie y una fuente alterna (ver figura superior) se pide realizar un
    *programa que permita calcular el potencial en cada uno de los puntos A, B, C y D para valores
    *coherentes de V0, , C, L y R (por ejemplo 220V, 50Hz, 1.2 µF, 3 mHr, 5 k).
     */

    // Datos del problema
    double V0 = 220;    // Voltaje de la fuente en V
    double nu = 50;     // Frecuencia en Hz
    double C = 1.2e-6;  // Capacitancia en F
    double L = 3e-3;    // Inductancia en H
    double R = 5000;    // Resistencia en Ω

    // Calcular frecuencia angular
    double w = FrecuenciaAngular(nu);

    // Calcular impedancias
    Complejo Zr = ImpedanciaR(R);
    Complejo Zc = ImpedanciaC(C, w);
    Complejo Zl = ImpedanciaL(L, w);
    Complejo Zt = ImpedanciaTotal(Zr, Zc, Zl);

    // Crear voltaje de la fuente (V0 + 0i)
    Complejo V = CrearComplejo(V0, 0);

    // Calcular intensidad
    Complejo I = Intensidad(V, Zt);

    // Calcular caídas de voltaje en cada elemento
    Complejo Vr = CaidaPotencial(I, Zr);
    Complejo Vc = CaidaPotencial(I, Zc);
    Complejo Vl = CaidaPotencial(I, Zl);

    // Imprimir resultados
    printf("Impedancia Total: %.2f + %.2fi Ohmnios\n", Zt.real, Zt.imag);
    printf("Frecuencia Angular: %.2f rad/s\n", w);
    printf("Intensidad: %.6f + %.6fi A\n", I.real, I.imag);
    printf("Voltaje en R: %.2f + %.2fi V\n", Vr.real, Vr.imag);
    printf("Voltaje en C: %.2f + %.2fi V\n", Vc.real, Vc.imag);
    printf("Voltaje en L: %.2f + %.2fi V\n", Vl.real, Vl.imag);

    printf("Voltaje en A: %.2f + %.2fi V\n", V.real, V.imag); // V0
    printf("Voltaje en B: %.2f + %.2fi V\n", Restar(Vr, Vc).real, Restar(Vr, Vc).imag);
    printf("Voltaje en C: %.2f + %.2fi V\n", Restar(V, Vr).real, Restar(V, Vr).imag);
    printf("Voltaje en D: 0 V"); // 0
}
