#include <stdio.h>

int main()
{
    int l1, l2, l3;
    printf("Ingrese los 3 lados del triangulo: ");
    scanf("%d %d %d", &l1, &l2, &l3);
    printf("El perimetro es: %d\n", l1 + l2 + l3);
    return 0;
}
