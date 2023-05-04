#include <stdio.h>

int main() {
    int a = 101, b = 12, c = 77;
    int max;

    if ((a >= b) && (a >= c)) max = a;
    if ((b >= a) && (b >= c)) max = b;
    if ((c >= a) && (c >= b)) max = c;

    printf("max=%d\n", max);
}