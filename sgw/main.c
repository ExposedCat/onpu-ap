#include <math.h>
#include <stdio.h>

void main() {
    // Define euro rates array
    double rates[7];

    // Input euro rates
    printf("Input euro rates for 7 days: ");
    for (unsigned index = 0; index < 7; ++index) {
        scanf("%lf", &rates[index]);
    }

    // Task A
    printf("\nTask A\n______\n");
    // 1. Find minimal and maximal euro rates
    double min = rates[0];
    double max = rates[0];
    // I'll store index of maximal element for task D
    double max_index = 0;
    for (unsigned index = 0; index < 7; ++index) {
        if (rates[index] < min) {
            // Update minimal euro rate
            min = rates[index];
        } else if (rates[index] > max) {
            // Update maximal euro rate and it's index
            max = rates[index];
            max_index = index;
        }
    }
    printf("Minimal rate: %5.2lf\nMaximal rate: %5.2lf\n", min, max);
    // Calculate difference between minimal and maximal euro rates
    double difference = max - min;
    printf("Difference: %5.2lf\n", difference);
    printf("\n");
    // 2. Print all days when euro rate was higher then specified
    double rate;
    printf("Input euro rate to filter: ");
    scanf("%lf", &rate);
    for (unsigned day = 0; day < 7; ++day) {
        if (rates[day] > rate) {
            // Print day and corresponding euro rate
            printf("Day %d: %5.2lf\n", day + 1, rates[day]);
        }
    }

    // Task B
    printf("\nTask B\n______\n");
    // 1. Determine if euro rate has been rising all the time
    unsigned rising = 1;  // 1 because there is no boolean in C
    // Check one less day to avoid segmentation fault on last day
    for (unsigned day = 0; day < 7 - 1; ++day) {
        // If euro rate of next day is lower then current
        if (rates[day + 1] < rates[day]) {
            // Set rising flag to 0 (false, but integer because
            // of boolean type non existence) and exit loop
            rising = 0;
            break;
        }
    }
    // 2. Print result
    if (rising) {
        printf("Euro rate rose\n");
    } else {
        printf("Euro rate did not rise\n");
    }

    // Task C
    printf("\nTask C\n______\n");
    // Find average between maximal and specified euro rates.
    // I'll use maximal value found in task A
    double max_rate;
    printf("Input euro rate to find average: ");
    scanf("%lf", &max_rate);
    // If specified number is greater or equal to maximal euro
    // rate then average will be equal to the only one
    // (maximal) value divided by 1
    if (max_rate >= max) {
        printf("Average of euro rates in specified interval is %5.2lf", max);
    } else {
        // Otherwise I'll find amount of euro rates in
        // specified interval and it's sum
        double sum = 0;
        double amount = 0;
        for (unsigned day = 0; day < 7; ++day) {
            double rate = rates[day];
            // If euro rate is in needed interval
            if (rate >= max_rate && rate <= max) {
                // Add rate to sum and increase amount of euro rates in interval
                sum += rate;
                amount++;
            }
        }
        // Find average by calculated sum and amount
        double average = sum / amount;
        printf("Average of euro rates in specified interval is %5.2lf\n", average);
    }

    // Task D
    printf("\nTask D\n______\n");
    // 1. Replace maximal euro rate by specified
    // I'll use index of maximal value found in task A
    double new_rate;
    printf("Input euro rate to replace maximal: ");
    scanf("%lf", &new_rate);
    // Converting to int is necessary because array index
    // must be an int, but not unsigned int (strange enough, actually).
    rates[(int)max_index] = new_rate;
    // 2. Print modified euro rates array
    printf("{ ");
    for (unsigned index = 0; index < 7; ++index) {
        printf("%5.3lf ", rates[index]);
    }
    printf("}");

    printf("\n\n");
}