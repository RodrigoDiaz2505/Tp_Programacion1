#include <stdio.h>

int main()
{
    float salario, bonificacion;
    int puntaje;
    int excelente = 0;
    int bueno = 0;
    int regular = 0;
    int deficiente = 0;

    for (int i = 1; i <= 3; i++)
    {
        printf("\nEmpleado%d\n", i);

        printf("Ingrese el salario base: ");
        scanf("%f", &salario);

        do
        {
            printf("Ingrese el puntaje de desempeno (1 a 10): ");
            scanf("%d", &puntaje);
            if (puntaje < 1 || puntaje > 10)
            {
                printf("Puntaje invalido... Debe estar entre 1 y 10.\n");
            }
        } while (puntaje < 1 || puntaje > 10);

        if (puntaje >= 9)
        {
            bonificacion = salario * 0.20;
            printf("Categoria de desempeno: Excelente\n");
            excelente++;
        }
        else if (puntaje >= 7)
        {
            bonificacion = salario * 0.10;
            printf("Categoria de desempeno: Bueno\n");
            bueno = bueno + 1;
        }
        else if (puntaje >= 5)
        {
            bonificacion = salario * 0.05;
            printf("Categoria de desempeno: Regular\n");
            regular = regular + 1;
        }
        else
        {
            bonificacion = 0.0;
            printf("Categoria de desempeno: Deficiente\n");
            deficiente = deficiente + 1;
        }

        printf("Bonficacion: $%.2f\n", bonificacion);
    }

    printf("\nResumen Final\n");
    printf("Empleados con desempeno Excelente: %d\n", excelente);
    printf("Empleados con desempeno Bueno: %d\n", bueno);
    printf("Empleados con desempeno Regular: %d\n", regular);
    printf("Empleados con desempeno Deficiente: %d\n", deficiente);

    return 0;
}
