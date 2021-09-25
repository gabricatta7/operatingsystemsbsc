#include <stdio.h>
#include <stdlib.h>

void copy_data(FILE *source, FILE *target) {
    unsigned long r, w;
    char buffer[4096];

    do {
        r = fread(buffer, 1, sizeof(buffer), source);
        w = 0;
        if (r > 0) {
            w = fwrite(buffer, 1, r, target);
        }
    } while ((r > 0) && (r == w));

    if (r != w) {
        perror("copy_data()");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    int i;
    FILE *source;

    if (argc <= 1) {
        copy_data(stdin, stdout);
    } else {
        for (i = 1; i < argc; i++) {
            if (!(source = fopen(argv[i], "rb"))) {
                perror("open()");
                exit(EXIT_FAILURE);
            }
            copy_data(source, stdout);
            fclose(source);
        }
    }
    exit(EXIT_SUCCESS);
}
