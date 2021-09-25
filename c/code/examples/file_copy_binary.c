#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 16

void copy_by_byte_blocks(FILE *source, FILE *target) {
    size_t n, m;
    unsigned char buffer[BUFFER_SIZE];
    do {
        n = fread(buffer, 1, sizeof(buffer), source);
        if (n) {
            m = fwrite(buffer, 1, n, target);
        } else {
            m = 0;
        }
    } while ((n > 0) && (n == m));

    if (m != 0) {
        perror("copy");
    }
}

int main() {
    char source_file[] = "../examples/example.c";
    char target_file[] = "example.c";
    char cwd[PATH_MAX];
    FILE *source, *target;

    /* show working directory */
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    }

    source = fopen(source_file, "rb");
    if (!source) {
        perror(source_file);
        exit(EXIT_FAILURE);
    }

    target = fopen(target_file, "wb");
    if (!target) {
        fclose(source);
        perror(target_file);
        exit(EXIT_FAILURE);
    }

    copy_by_byte_blocks(source, target);

    printf("[OK] %s -> %s\n", source_file, target_file);

    fclose(source);
    fclose(target);
    exit(EXIT_SUCCESS);
}