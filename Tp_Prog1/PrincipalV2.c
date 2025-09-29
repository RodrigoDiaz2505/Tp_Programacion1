#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{

    int legajo, turno, modalidad;
    float montoFinal;
    float arancel = 25000;
    bool hayError = false;
    bool deseaContinuar;
    char respuesta;

    do
    {
        // cada vez que itera una inscripcion se resetea el estado de error
        hayError = false;

        // Mensaje de bienvenida
        printf("Bienvenido al sistema de inscripciones de alumnos\n");

        // Solicitar legajo
        printf("Ingrese su numero de legajo: ");
        scanf("%d", &legajo);

        // Validacion de legajo
        if (legajo < 1000 || legajo > 9999)
        {
            printf("Legajo fuera de rango debe ser (entre 1000 y 9999)\n");
            hayError = true;
        }
        else
        {
            // Solicitar turno
            do // este do soluciona la validacion (Ya no termina y se pierde la entrada anterior en caso de error)
            {
                printf("Seleccione su turno: \n");
                printf("1 - Maniana\n");
                printf("2 - Tarde\n");
                printf("3 - Noche\n");
                scanf("%d", &turno);
            } while (turno < 1 || turno > 3);

            switch (turno)
            {
            case 1: // Mañana
            case 2: // Tarde
                // modalidad
                do
                {
                    printf("Seleccione la modalidad: \n");
                    printf("1 - Presencial\n");
                    printf("2 - Virtual\n");
                    scanf("%d", &modalidad);
                } while (modalidad < 1 || modalidad > 2);

                switch (modalidad)
                {
                case 1: // Presencial
                    montoFinal = arancel * 1.10;
                    break;
                case 2: // Virtual
                    montoFinal = arancel * 1.05;
                    break;
                default:
                    printf("Modalidad invalida.\n");
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
                printf("Turno invalido...\n");
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

        // se verifica si el usuario desea continuar
        do
        {
            printf("\nDesea continuar? (s/n): ");
            scanf(" %c", &respuesta);

            if (respuesta == 's' || respuesta == 'S')
            {
                deseaContinuar = true;
            }
            else if (respuesta == 'n' || respuesta == 'N')
            {
                deseaContinuar = false;
            }
            else
            {
                printf("Respuesta invalida... 's' para continuar o 'n' para salir.\n");
            }

        } while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N');

    } while (deseaContinuar == true);

    return 0;
    // falta correjir validaciones
}
