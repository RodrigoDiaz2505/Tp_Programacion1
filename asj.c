#include <stdio.h>
int main()
{
    int n;
    int suma = 0;
    printf("Ingrese un numero entero positivo: \n");
    scanf("%d", &n);
    suma = suma + n;
    printf("%d", n);
    for (int i = 0; i <= n; i += 2)
    {
        printf("%d", i);
    }

    return 0;
}