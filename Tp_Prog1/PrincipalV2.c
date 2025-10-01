#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{

    int legajo, turno, modalidad;
    float montoFinal;
    float arancel = 25000;
    float recaudacionTotal = 0;
    bool hayError = false;
    bool deseaContinuar;
    char respuesta;
    int cantInscripciones = 0;
    int cantMañana = 0;
    int cantTarde = 0;
    int cantNoche = 0;
    int cantPresencial = 0;
    int cantVirtual = 0;

    do
    {
        // cada vez que itera una inscripcion se resetea el estado de error
        hayError = false;

        // Mensaje de bienvenida
        printf("Bienvenido al sistema de inscripciones de alumnos\n");

        // Solicitar legajo
        printf("Ingrese su numero de legajo: \n");
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
            do
            {
                printf("Seleccione su turno: \n");
                printf("1 - Maniana\n");
                printf("2 - Tarde\n");
                printf("3 - Noche\n");
                fflush(stdin); // limpia Buffer para evitar bucles , fuente : https://youtu.be/AFcvGLEMgFU?si=l2phs4TQgl2WQ-Bq
                scanf("%d", &turno);
                fflush(stdin);
                if (turno < 1 || turno > 3)
                {
                    printf("Opcion invalida , la opcion es un caracter o esta fuera de rango...\n");
                }

            } while (turno < 1 || turno > 3);

            switch (turno)
            {
            case 1: // Mañana
                    // y
            case 2: // Tarde

                if (turno == 1)
                {
                    cantMañana = cantMañana + 1;
                }
                else if (turno = 2)

                {
                    cantTarde = cantTarde + 1;
                }

                // modalidad
                do
                {
                    printf("Seleccione la modalidad: \n");
                    printf("1 - Presencial\n");
                    printf("2 - Virtual\n");
                    fflush(stdin);
                    scanf("%d", &modalidad);
                    fflush(stdin);
                    if (modalidad < 1 || modalidad > 2)
                    {
                        printf("Opcion invalida , la opcion es un caracter o esta fuera de rango...\n");
                    }
                } while (modalidad < 1 || modalidad > 2);

                switch (modalidad)
                {
                case 1: // Presencial
                    montoFinal = arancel * 1.10;
                    cantPresencial = cantPresencial + 1;
                    break;
                case 2: // Virtual
                    montoFinal = arancel * 1.05;
                    cantVirtual = cantVirtual + 1;
                    break;
                default:
                    printf("Modalidad invalida...\n");
                    hayError = true;
                    break;
                }
                break;

            case 3: // Noche
                modalidad = 1;
                montoFinal = arancel * 1.10;
                montoFinal = montoFinal * 0.92; // Descuento del 8%
                cantNoche = cantNoche + 1;
                cantPresencial = cantPresencial + 1;
                break;

            default:
                printf("Turno invalido...\n");
                hayError = true;
                break;
            }
            cantInscripciones = cantInscripciones + 1;
            recaudacionTotal = recaudacionTotal + montoFinal;
        }

        // Mostrar resumen si no hubo errores
        if (hayError == false)
        {
            // Mostrar turno
            char *turnoStr; // Se utilizaron punteros . Fuente ; https://youtu.be/wqwgQZn1hco?si=7n6VfAGcAl161NdX
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
            // Resumen general de las inscripciones
            printf("\nRESUMEN DE INSCRIPCION\n");
            printf("Legajo: %d\n", legajo);
            printf("Turno: %s\n", turnoStr);
            printf("Modalidad: %s\n", modalidadStr);
            printf("Monto total de esta Inscripcion: $%.2f\n", montoFinal);
            printf("Resumen de Operaciones: \n");
            printf("Cantidad de inscripciones Totales: %d\n", cantInscripciones);
            printf("La cantidad de alumnos en turno maniana: %d\n", cantMañana);
            printf("La cantidad de alumnos en turno tarde: %d\n", cantTarde);
            printf("La cantidad de alumnos en turno noche: %d\n", cantNoche);
            printf("Cantidad que cursan presencial: %d\n", cantPresencial);
            printf("Cantidad que cursan Virtual: %d\n", cantVirtual);
            printf("Recaudacion total: $%.2f\n", recaudacionTotal);
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

    if (deseaContinuar == false)
    {
        printf("Hasta Pronto..."); // Mensaje de salida
    }

    return 0;
}
