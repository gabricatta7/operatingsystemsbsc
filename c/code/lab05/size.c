#include <stdio.h>
#include <stdlib.h>

#define BUFFER_MAX 4096

int main(int argc, char *argv[]) {
    FILE *source;
    char buffer[BUFFER_MAX];
    unsigned long r, count = 0;

    if (argc != 2) {
        fprintf(stdout, "usage: %s filename\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    if (!(source = fopen(argv[1], "r"))) {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    while ((r = fread(buffer, 1, sizeof(buffer), source)) > 0) {
	    count += r;
    }

    fprintf(stdout, "size=%ld bytes\n", count);
    fclose(source);
    exit(EXIT_SUCCESS);
}
