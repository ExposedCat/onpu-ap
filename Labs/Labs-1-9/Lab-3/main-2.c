#include <stdio.h>
#include <math.h>
void main() {
    double a, x, y;
    scanf("%lf", &a);
    y = x + 3 > fabs(a) ? x - a : (x + 3 < fabs(a) ? x * 5 : a / 3);
    printf("-----------------\n");
    printf("|      x|      y|\n");
    printf("-----------------\n");
    printf("|%7.2lf|%7.2lf|\n\n", x, y);
    printf("-----------------\n");
}