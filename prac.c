#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int cuenta;
    float saldo;
} Cliente;

int main()
{
    Cliente clientes[100];
    int total_clientes = 0;
    int opcion;

    do
    {
        printf("\n===== BANCO SIMULADO =====\n");
        printf("1. Registrar cliente\n");
        printf("2. Consultar saldo\n");
        printf("3. Depositar dinero\n");
        printf("4. Retirar dinero\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            // Registrar cliente
            if (total_clientes < 100)
            {
                Cliente nuevo;
                printf("Ingrese nombre del cliente: ");
                scanf("%s", nuevo.nombre);
                nuevo.cuenta = 1000 + total_clientes; // N° de cuenta automático
                nuevo.saldo = 0.0;
                clientes[total_clientes] = nuevo;
                printf("Cliente registrado. Numero de cuenta: %d\n", nuevo.cuenta);
                total_clientes++;
            }
            else
            {
                printf("No se pueden registrar mas clientes.\n");
            }
        }
        else if (opcion == 2)
        {
            // Consultar saldo
            int cuenta;
            printf("Ingrese numero de cuenta: ");
            scanf("%d", &cuenta);
            int encontrado = 0;
            for (int i = 0; i < total_clientes; i++)
            {
                if (clientes[i].cuenta == cuenta)
                {
                    printf("Cliente: %s | Saldo: %.2f\n", clientes[i].nombre, clientes[i].saldo);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                printf("Cuenta no encontrada.\n");
            }
        }
        else if (opcion == 3)
        {
            // Depositar dinero
            int cuenta;
            float monto;
            printf("Ingrese numero de cuenta: ");
            scanf("%d", &cuenta);
            int encontrado = 0;
            for (int i = 0; i < total_clientes; i++)
            {
                if (clientes[i].cuenta == cuenta)
                {
                    printf("Ingrese monto a depositar: ");
                    scanf("%f", &monto);
                    clientes[i].saldo += monto;
                    printf("Deposito exitoso. Saldo actual: %.2f\n", clientes[i].saldo);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                printf("Cuenta no encontrada.\n");
            }
        }
        else if (opcion == 4)
        {
            // Retirar dinero
            int cuenta;
            float monto;
            printf("Ingrese numero de cuenta: ");
            scanf("%d", &cuenta);
            int encontrado = 0;
            for (int i = 0; i < total_clientes; i++)
            {
                if (clientes[i].cuenta == cuenta)
                {
                    printf("Ingrese monto a retirar: ");
                    scanf("%f", &monto);
                    if (monto <= clientes[i].saldo)
                    {
                        clientes[i].saldo -= monto;
                        printf("Retiro exitoso. Saldo actual: %.2f\n", clientes[i].saldo);
                    }
                    else
                    {
                        printf("Fondos insuficientes.\n");
                    }
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                printf("Cuenta no encontrada.\n");
            }
        }
        else if (opcion == 5)
        {
            printf("Saliendo del sistema...\n");
        }
        else
        {
            printf("Opcion no valida.\n");
        }

    } while (opcion != 5);

    return 0;
}
