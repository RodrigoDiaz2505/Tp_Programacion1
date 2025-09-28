#include <stdio.h>

int main()
{
    int dni;
    int medioPago;
    int tarjeta;
    int cuotas;
    float total = 4600.0;

    printf("Ingrese su DNI: ");
    scanf("%d", &dni);

    if (dni < 1000000 || dni > 99999999)
    {
        printf("Error: DNI invalido.\n");
        return 0;
    }

    do
    {
        printf("Seleccione medio de pago:\n");
        printf("1- Efectivo\n");
        printf("2- Tarjeta de credito\n");
        scanf("%d", &medioPago);

        if (medioPago != 1 && medioPago != 2)
        {
            printf("Error... Medio de pago invalido.\n");
        }

    } while (medioPago != 1 && medioPago != 2);

    if (medioPago == 1)
    {
        cuotas = 1;
    }
    else
    {
        do
        {
            printf("Seleccione tarjeta:\n");
            printf("1- Visa\n");
            printf("2- American Express\n");
            printf("3- Mercado Pago\n");
            printf("4- Cabal\n");
            scanf("%d", &tarjeta);

            if (tarjeta < 1 || tarjeta > 4)
            {
                printf("Error: Tarjeta invalida.\n");
            }
        } while (tarjeta > 1 && tarjeta < 4);

        printf("Seleccione cantidad de cuotas (1, 3, 6 o 12): ");
        scanf("%d", &cuotas);

        if (cuotas != 1 && cuotas != 3 && cuotas != 6 && cuotas != 12)
        {
            printf("Error: Cantidad de cuotas invalida.\n");
            return 0;
        }
    }

    if (cuotas == 3)
    {
        total *= 1.04;
    }
    else if (cuotas == 6 || cuotas == 12)
    {
        total *= 1.08;
    }

    printf("\nRESUMEN DE OPERACION\n");
    printf("DNI: %d\n", dni);
    printf("Medio de pago: ");
    if (medioPago == 1)
    {
        printf("Efectivo\n");
    }
    else
    {
        printf("Tarjeta de credito\n");
        printf("Tarjeta: ");
        switch (tarjeta)
        {
        case 1:
            printf("Visa\n");
            break;
        case 2:
            printf("American Express\n");
            break;
        case 3:
            printf("Mercado Pago\n");
            break;
        case 4:
            printf("Cabal\n");
            break;
        }
        printf("Cuotas: %d\n", cuotas);
    }
    printf("Total: $%.2f\n", total);

    return 0;
}
