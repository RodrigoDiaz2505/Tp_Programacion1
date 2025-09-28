#include <stdio.h>

int main()
{
    float nota, suma = 0;
    int contador = 0;
    char opcion;

    do
    {
        printf("Ingrese una nota: ");
        scanf("%f", &nota);

        suma += nota;
        contador++;

        printf("¿Desea ingresar otra nota? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    if (contador > 0)
    {
        printf("\nSuma de notas: %.2f", suma);
        printf("\nPromedio: %.2f\n", suma / contador);
    }
    else
    {
        printf("\nNo se ingresaron notas.\n");
    }

    return 0;
}
