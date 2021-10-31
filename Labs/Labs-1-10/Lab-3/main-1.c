#include <stdio.h>
#include <math.h>
void main()
{
    double x, y;
    scanf("%lf %lf", &x, &y);
    if (
        x * x + y * y <= 1 &&
        (y >= x + 1 ||
         y >= 1 - x))
    {
        printf("Yes\n\n");
    }
    else if (
        y <= 0 &&
        y >= x - 1 &&
        y >= -1 - x)
    {
        printf("Yes\n\n");
    }
    else
    {
        printf("No\n\n");
    }
}