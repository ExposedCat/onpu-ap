#include <stdio.h>
#include <math.h>
void main() {
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    double a, b;
    a = (4 * cbrt(pow(sin(y * M_PI / 180), 3)) - 1.2 * pow(10, -6) * z) / (1 / x / x + exp(-3 * x));
    b = x - (z * z / 5) + (1 / (x - y)) + exp(-2 * y);
    printf("a = %9.3lf\nb = %9.3lf\n\n", a, b);
}