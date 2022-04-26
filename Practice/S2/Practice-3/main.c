#include <stdio.h>

double get_odds_sum(double* array, int size);

int main() {
    const int size = 5;
    const double array[5] = {1.0, 2.5, 3.0, 4.9, 5.0};
    const double odds_sum = get_odds_sum(array, size);
    printf("%lf", odds_sum); // 9.0
    return 0;
}

double get_odds_sum(double* array, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        if ((int)array[i] % 2) {
            sum += array[i];
        }
    }
    return sum;
}