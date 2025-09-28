int main()
{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
    // Tp de programacion 1
    int NumLegajo, turno, modalidad;
    float recargo1 = 1.10;
    float recargo2 = 1.05;
    float descuentoNoche = 0.08;
    bool VarBandera;
    printf("Bienvenido al sistema de inscripciones de alumnos");
    printf("Ingrese El Numero de Legajo: ");
    scanf("%i", &NumLegajo);
    if (NumLegajo < 1000 || NumLegajo > 9999)
    {
        Printf("Legajo fuera de rango...");
    }

    return 0;
}