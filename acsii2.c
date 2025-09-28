#include <stdio.h>

int main()
{
    char x, y;

    printf("Ingresa dos caracteres: ");
    scanf(" %c %c", &x, &y);

    printf("Codigo ASCII de '%c' = %d\n", x, x);
    printf("Codigo ASCII de '%c' = %d\n", y, y);
    printf("Suma = %d\n", x + y);

    return 0;
}
