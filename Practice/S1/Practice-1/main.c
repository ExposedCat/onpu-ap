#include <stdio.h>
#include <math.h>
void main() {
    double a, b, c;
    printf("Input sides of triangle\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (
        a + b <= c || a + c <= b || b + c <= a ||
        a <= 0 || b <= 0 || c <= 0
    ) {
        printf("Triangle does not exist\n\n");
        return;
    }

    if (a == b || a == c || b == c) {
        if (a == b && a == c) {
            printf("Triangle is equilateral\n");
        } else {
            printf("Triangle is isosceles\n");
        }
    } else {
        printf("Triangle is arbitrary\n");
    }

    double p = (a + b + c) / 2;
    double s = sqrt(
        p * (p - a) * (p - b) * (p - c)
    );
    printf("Triangle area = %.2lf\n\n", s);
}