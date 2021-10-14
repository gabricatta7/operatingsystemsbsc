#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    float x;
    float y;
} point_t;

point_t *allocate_point(float x, float y) {
    point_t *p = malloc(sizeof(point_t));
    p->x = x;
    p->y = y;
    return p;
}

void free_point(point_t *p) {
    free(p);
}

void show_point(point_t *p) {
    printf("(%f,%f)\n", p->x, p->y);
}

int main() {
    point_t *p = allocate_point(2, 3);
    show_point(p);
    free_point(p);
}