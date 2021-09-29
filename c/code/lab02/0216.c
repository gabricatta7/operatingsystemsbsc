#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void init(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

/* Function to implement bubble sort */
void sort(int arr[], int n) {
    int i, j, tmp, changed;
    for (i = 0; i < n-1; i++) {
        changed = FALSE;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                changed = TRUE;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        if (!changed) break;
    }
}

/* Function to search a value within an array */
int search(const int arr[], int size, int value) {
    int i;
    for (i = 0; i < size; i++ ) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

/* Function to print an array */
void show(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("[%d] %d\n", i, arr[i]);
    }
}

int main() {
    int arr[100];
    int n = sizeof(arr) / sizeof(arr[0]);

    init(arr, n);
    sort(arr, n);
    show(arr, n);
    printf("%d index=%d\n", 10, search(arr, n, 10));
}
