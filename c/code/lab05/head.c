#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc , char *argv[]) {
    FILE  *source;

    char buffer[LINE_MAX];
    int lines;

    if (argc != 3) {
        fprintf(stdout, "Usage: %s filename n\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    lines = atoi(argv[2]);

    if (!(source = fopen(argv[1], "r"))) {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    while (((fgets(buffer, LINE_MAX, source)) != NULL) && (lines-- > 0)) {
        fputs(buffer, stdout);
    }

    fclose(source);
    exit(EXIT_SUCCESS);
}