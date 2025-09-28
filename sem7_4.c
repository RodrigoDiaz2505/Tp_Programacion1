#include <stdio.h>
#include <math.h>

int main()
{
    float cat1, cat2, hip, perimetro, superficie;
    printf("Ingrese los 2 catetos del triangulo rectangulo: ");
    scanf("%f %f", &cat1, &cat2);
    hip = hypot(cat1, cat2);
    perimetro = cat1 + cat2 + hip;
    superficie = (cat1 * cat2) / 2;
    printf("Hipotenusa: %.2f\nPerimetro: %.2f\nSuperficie: %.2f\n", hip, perimetro, superficie);
    return 0;
}
