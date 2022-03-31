#include <stdio.h>
#include <stdlib.h>


int main(void) {
#define MAX 128 \
    printf("%d\n", MAX);
#undef MAX
    printf("%d\n", MAX);    /* Errore! */
}
