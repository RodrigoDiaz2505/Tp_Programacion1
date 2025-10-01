#include <stdio.h>

int main()
{
    int legajo, turno, modalidad;
    float montoBase = 25000, recargo, descuento, total;
    char opcion;

    int cantTotal = 0;
    int cantMañana = 0, cantTarde = 0, cantNoche = 0;
    int cantPresencial = 0, cantVirtual = 0;
    float recaudacionTotal = 0;

    do
    {

        do
        {
            printf("Ingrese su numero de legajo (1000 - 9999): ");
            scanf("%d", &legajo);
            if (legajo < 1000 || legajo > 9999)
            {
                printf("Error: Legajo invalido.\n");
            }
        } while (legajo < 1000 || legajo > 9999);

        do
        {
            printf("Seleccione el turno:\n1 - Manana\n2 - Tarde\n3 - Noche\n");
            scanf("%d", &turno);
            if (turno < 1 || turno > 3)
            {
                printf("Error: turno invalido.\n");
            }
        } while (turno < 1 || turno > 3);

        recargo = 0;
        descuento = 0;
        switch (turno)
        {
        case 1: // Mañana
        case 2: // Tarde
            do
            {
                printf("Seleccione la modalidad:\n1 - Presencial\n2 - Virtual\n");
                scanf("%d", &modalidad);
                if (modalidad < 1 || modalidad > 2)
                {
                    printf("Error: modalidad invalida.\n");
                }
            } while (modalidad < 1 || modalidad > 2);

            if (modalidad == 1)
            {
                recargo = montoBase * 0.10;
                cantPresencial++;
            }
            else
            {
                recargo = montoBase * 0.05;
                cantVirtual++;
            }
            break;

        case 3:            // Noche
            modalidad = 1; // Presencial fija
            recargo = montoBase * 0.10;
            descuento = (montoBase + recargo) * 0.08;
            cantPresencial++;
            cantNoche++;
            break;
        }

        total = montoBase + recargo - descuento;
        recaudacionTotal += total;
        cantTotal++;

        if (turno == 1)
            cantMañana++;
        else if (turno == 2)
            cantTarde++;
        else
            cantNoche++;

        printf("\n-RESUMEN DE INSCRIPCION-\n");
        printf("Legajo: %d\n", legajo);
        if (turno == 1)
            printf("Turno: Manana\n");
        else if (turno == 2)
            printf("Turno: Tarde\n");
        else
            printf("Turno: Noche\n");

        if (modalidad == 1)
            printf("Modalidad: Presencial\n");
        else
            printf("Modalidad: Virtual\n");

        printf("Monto total: $%.2f\n", total);

        do
        {
            printf("\nDesea registrar otro alumno? (S/N): ");
            scanf(" %c", &opcion);
            if (opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n')
            {
                printf("Error: opcion invalida.\n");
            }
        } while (opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n');

    } while (opcion == 'S' || opcion == 's');

    printf("Cantidad total de inscripciones: %d\n", cantTotal);
    printf("Alumnos en turno Manana: %d\n", cantMañana);
    printf("Alumnos en turno Tarde: %d\n", cantTarde);
    printf("Alumnos en turno Noche: %d\n", cantNoche);
    printf("Alumnos modalidad Presencial: %d\n", cantPresencial);
    printf("Alumnos modalidad Virtual: %d\n", cantVirtual);
    printf("Recaudacion total: $%.2f\n", recaudacionTotal);

    return 0;
}