#include <stdio.h>

int main() {
    unsigned i;

    for (i = 0; i <= 255; i++) {
        printf("%3u %3x %3c\n", i, i, i);
    }
}