#include <stdio.h>
#include <stdlib.h>

void main() {
    unsigned n, k;
    do {
        printf("Input N, K (Ctrl + C to exit): ");
        scanf("%d %d", &n, &k);
        if (n < k) {
            printf("N must be bigger then K\n");
        }
    } while (n < k);

    unsigned *a = malloc(sizeof(int) * n);
    unsigned *b = malloc(sizeof(int) * k);
    printf("A: ");
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    printf("B: ");
    for (unsigned i = 0; i < k; ++i) {
        scanf("%d", b + i);
    }

    unsigned index;
    for (unsigned i = 0; i < n; ++i) {
        if (*b == *(a + i)) {
            index = 0;
            for (unsigned j = 0; j < k; ++j) {
                if (*(b + j) != *(a + i + j)) {
                    index = -1;
                    break;
                }
            }
            if (index != -1) {
                index = i;
                break;
            }
        }
    }

    if (index == -1) {
        printf("Subarray not found\n");
    } else {
        printf("Subarray found at {%d; %d}: [ ", index, index + k);
        for (unsigned i = 0; i < n; ++i) {
            if (i == index) {
                printf("{");
            } else if (i == index + k - 1) {
                printf("%d} ", *(a + i));
                continue;
            }
            printf("%d ", *(a + i));
        }
        printf("]\n");
    }

    printf("\n");
}