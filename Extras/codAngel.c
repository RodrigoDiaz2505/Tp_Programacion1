#include <stdio.h>
#include <stdbool.h>

int main()
{
    int numleg, cantinscrip = 0;
    char decision;
    float montototal = 25000, montofinal = 25000, descuento = 0, recargo = 0, Recaudaciontotal = 0;
    bool banderaerror = false;
    int turno, modalidad, alumnosM = 0, alumnosT = 0, alumnosN = 0;
    int cantidadvirtual = 0, cantpresencial = 0;

    do
    {
        printf("Bienvenido!\n");
        do
        {
            printf("Ingrese el numero de legajo: \n");
            scanf("%d", &numleg);

            if (numleg > 9999 || numleg < 1000)
            {
                (banderaerror == true);
                printf("fuera de rango, solo se admite 1000 al 9000\n");
            }
        } while (numleg > 9999 || numleg < 1000);

        if (banderaerror == false)
        {
            do
            {
                printf("En que turno desea cursar?\n\n");
                printf("Seleccione una opcion (1-3)\n");
                printf(" 1 - Turno mañana \n");
                printf(" 2 - Turno tarde:    \n");
                printf(" 3 - Turno noche:    \n");
                scanf("%d", &turno);
                if (turno > 3 || turno < 1)
                {
                    printf("turno no valido\n");
                }
            } while (turno > 3 || turno < 1);
            if (turno == 1)
            {
                alumnosM = alumnosM + 1;
            }
            switch (turno)
            {

            case 1:
            case 2:
                printf("Seleccione modalidad\n");
                if (turno == 2)
                {
                    alumnosT = alumnosT + 1;
                }
                printf("1 - Presencial \n");
                printf("2 - Virtual\n");
                scanf("%d", &modalidad);
                if (modalidad > 2 || modalidad < 1)
                {

                    printf("fuera de modalidad ingrese 1 o 2\n");
                }
                switch (modalidad)
                {
                case 1:
                    recargo = (25000 * 0.10);
                    montototal = (25000 + recargo);
                    break;
                case 2:
                    recargo = (25000 * 0.05);
                    montototal = (25000 + recargo);
                    break;
                }
                break;

            case 3:
                printf("modalidad presencial\n\n"); // turno noche modalidad presencial
                if (turno == 3)
                {
                    (alumnosN = alumnosN + 1);
                }
                recargo = 25000 * 0.10;          // recargo 10%
                montofinal = (25000 + recargo);  // monto total +recargo - el descuento
                descuento = (montofinal * 0.08); // descuento 8%
                montototal = (montofinal - descuento);
                break;
            default:
                printf("turno invalido");
            }

            if (banderaerror == false)
            {

                printf("---RESUMEN DE INSCRIPCION---\n");
                printf("Legajo: %d\n", numleg);
                switch (turno)
                {
                case 1:
                    printf("Turno mañana\n");
                    break;
                case 2:
                    printf("turno tarde´n");
                    break;
                case 3:
                    printf("turno noche\n");
                    break;
                }
                printf("Modalidad: \t");
                if (modalidad = 1)
                {
                    cantpresencial = cantpresencial + 1;

                    printf("Presencial\n");
                }
                else
                {
                    printf(" Virtual\n");
                    cantidadvirtual = cantidadvirtual + 1;
                }

                printf("Monto total:AR$ %.2f\n\n", montototal);
            }
            printf("Desea registrar otro alumno?: s/n \n\n");
            scanf("%s", &decision);
        }
        Recaudaciontotal = Recaudaciontotal + montototal; // suma de la recaudacion total
        cantinscrip = cantinscrip + 1;                    // inscripciones como suma
    } while (decision == 's' || decision == 'S');
    if (decision == 'n' || decision == 'N')
    {
        printf("---Resumen---\n\n");
        printf("---Estadísticas finales---\n");
        printf("Cantidad total de inscripciones: %d.\n\n", cantinscrip);
        printf("Cantidad de alumnos por turno.\n");
        printf("Turno mañana:                   %d\n", alumnosM);
        printf("Turno tarde:                     %d\n", alumnosT);
        printf("Turno noche:                     %d\n\n", alumnosN);
        printf("Cantidad de alumnos por modalidad:\n");
        printf("presencial:                      %d\n", cantpresencial);
        printf("Virtual:                         %d\n", cantidadvirtual);
        printf("Recaudación total acumulada:     %.2f\n", Recaudaciontotal);
    }
    return 0;
}