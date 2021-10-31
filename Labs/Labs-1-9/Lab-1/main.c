#include <stdio.h>
void main() {
    const float pi = 3.141;
    float h, r, s;
    printf("Input H\n");
    scanf("%f", &h);
    printf("Input R\n");
    scanf("%f", &r);
    s = 2 * pi * r * h;
    printf("%.3f", s);
}