#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *str = "hello world!";
    char *str_copy = strdup(str);

    printf("%s %s\n", str, str_copy);

    free(str_copy);

    /* error: pointer being freed was not allocated */
    free(str);
}