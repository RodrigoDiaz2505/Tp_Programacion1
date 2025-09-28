#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{

    int legajo, turno, modalidad;
    float montoFinal;
    float arancel = 25000;
    bool hayError = false;

    // Mensaje de bienvenida
    printf("Bienvenido al sistema de inscripciones de alumnos\n");

    // Solicitar legajo
    printf("Ingrese su numero de legajo: ");
    scanf("%d", &legajo);

    // Validación de legajo
    if (legajo < 1000 || legajo > 9999)
    {
        printf("ERROR: Legajo fuera de rango debe ser (entre 1000 y 9999).\n");
        hayError = true;
    }
    else
    {
        // Solicitar turno
        printf("Seleccione su turno:\n");
        printf("1 - Maniana\n");
        printf("2 - Tarde\n");
        printf("3 - Noche\n");
        scanf("%d", &turno);

        switch (turno)
        {
        case 1: // Mañana
        case 2: // Tarde
            // Pedir modalidad
            printf("Seleccione la modalidad:\n");
            printf("1 - Presencial\n");
            printf("2 - Virtual\n");
            scanf("%d", &modalidad);

            switch (modalidad)
            {
            case 1: // Presencial
                montoFinal = arancel * 1.10;
                break;
            case 2: // Virtual
                montoFinal = arancel * 1.05;
                break;
            default:
                printf("ERROR: Modalidad invalida.\n");
                hayError = true;
                break;
            }
            break;

        case 3: // Noche
            modalidad = 1;
            montoFinal = arancel * 1.10;
            montoFinal = montoFinal * 0.92; // Descuento del 8%
            break;

        default:
            printf("ERROR: Turno invalido.\n");
            hayError = true;
            break;
        }
    }

    // Mostrar resumen si no hubo errores
    if (!hayError)
    {
        // Mostrar turno
        char *turnoStr;
        if (turno == 1)
            turnoStr = "Maniana";
        else if (turno == 2)
            turnoStr = "Tarde";
        else
            turnoStr = "Noche";

        // Mostrar modalidad
        char *modalidadStr;
        if (modalidad == 1)
            modalidadStr = "Presencial";
        else
            modalidadStr = "Virtual";

        printf("\nRESUMEN DE INSCRIPCION\n");
        printf("Legajo: %d\n", legajo);
        printf("Turno: %s\n", turnoStr);
        printf("Modalidad: %s\n", modalidadStr);
        printf("Monto total: $%.2f\n", montoFinal);
    }

    return 0;
}
