#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc , char *argv[]) {
    FILE  *source;

    char buffer[LINE_MAX];
    int n, lines, start;

    if (argc != 3) {
        fprintf(stdout, "Usage: %s filename n\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    lines = atoi(argv[2]);

    if (!(source = fopen(argv[1], "r"))) {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    // count lines
    n = 0;
    while (((fgets(buffer, LINE_MAX, source)) != NULL)) n++;

    // define the first line to be printed out
    start = n - lines;
    if (start < 0) start = 0;

    // skip lines
    rewind(source);
    n = 0;
    while ((n++ < start) && ((fgets(buffer, LINE_MAX, source)) != NULL));

    // print last lines
    while ((fgets(buffer, LINE_MAX, source)) != NULL) {
        fputs(buffer, stdout);
    }

    fclose(source);
    exit(EXIT_SUCCESS);
}