
#include <stdio.h>

int main()
{
    int i, suma = 0;

    for (i = 1; i <= 10; i++)
    {
        suma += i * 3;
    }

    printf("La suma de los 10 primeros multiplos de 3 es: %d\n", suma);

    return 0;
}
