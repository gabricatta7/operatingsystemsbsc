#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void copy_data(FILE *source, FILE *target) {
    unsigned long nread, nwrite;
    char buffer[4096];

    do {
        nread = nwrite = 0;
        nread = fread(buffer, 1, sizeof(buffer), source);
        if (nread > 0) {
            nwrite = fwrite(buffer, 1, nread, target);
        }
    } while ((nread > 0) && (nread == nwrite));

    if (nread != nwrite) {
        perror("copy_data()");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    FILE *source, *target;

    if (argc != 3) {
        fprintf(stdout, "Usage: %s src dst\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (!(source = fopen(argv[1], "r"))) {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    if (!(target = fopen(argv[2], "w"))) {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    copy_data(source, target);

    fclose(source);
    fclose(target);

    exit(EXIT_SUCCESS);
}
