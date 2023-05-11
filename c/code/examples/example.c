#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point_t;

typedef struct {
    point_t begin;
    point_t end;
} line_t;

double length(const line_t *line) {
    return hypot(line->begin.x - line->end.x, line->begin.y - line->end.y);
}

int main(void) {
    line_t line = {
            .begin = {.x = 0.0, .y = 0.0},
            .end = {.x = 10.0, .y = 10.0}
    };
    printf("length=%lf\n", length(&line));
}