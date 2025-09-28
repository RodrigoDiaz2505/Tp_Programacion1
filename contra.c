#include <stdio.h>
#define CONTRASENA 1234
#define MAXIMOINTENTO 3

int main()
{
    int contra;
    int contrasena_actual = CONTRASENA;
    int intento = 0;
    int accesoconcedido = 0;

    while (intento < MAXIMOINTENTO && !accesoconcedido)
    {
        printf("Ingrese contrasena: ");
        scanf("%i", &contra);

        if (contra == contrasena_actual)
        {
            printf("Acceso concedido\n");
            accesoconcedido = 1;
        }
        else
        {
            intento++;
            if (intento < MAXIMOINTENTO)
            {
                printf("Contrasena incorrecta, intente nuevamente\n");
            }
        }
    }

    if (!accesoconcedido)
    {
        printf("Cuenta bloqueada\n");
        return 0;
    }

    int opcion;
    do
    {
        printf("\nMENU\n");
        printf("1. Cambiar contrasena\n");
        printf("2. Salir\n");
        printf("Elija una opcion: ");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:
        {
            int nueva;
            printf("Ingrese nueva contrasena numerica: ");
            scanf("%i", &nueva);
            contrasena_actual = nueva;
            printf("A cambiado su contrasena...\n");
            break;
        }
        case 2:
            printf("Saliendo del sistema...\n");
            break;
        default:
            printf("Opcion no valida, intente de nuevo\n");
        }

    } while (opcion != 2);

    return 0;
}