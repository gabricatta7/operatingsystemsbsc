#include <stdio.h>

int main() {
    unsigned n = 10;
    double somma_inversi = 0.0;
    int i;

    for (i = 1; i <= n; i++) {
        somma_inversi += 1 / (double) i;
    }
    printf("somma_inversi=%lf\n", somma_inversi);
}