// Copyright 2022 gonzalol
#include <stdio.h>
#include <stdlib.h>

int input(int ** a, int * n);
void output(int ** a, int n);
void sort(int *a, int n);

int main() {
    int n, inputRes;
    int * a;
    inputRes = input(&a, &n);
    if (inputRes != 0) {
        if (inputRes == -1) {
            printf("n/a");
            free(a);
        } else {
            printf("n/a");
        }
        return 1;
    }
    sort(a, n);
    output(&a, n);
    return 0;
}

int input(int **a, int * n) {
    char c;
    int check = 0;
    if (scanf("%d", n) == 1 && *n > 0) {
        *a = (int *) malloc(*n * sizeof(int));
        for (int j = 0; j < *n; j++) {
            if (check != 0 || scanf("%d", *a + j) != 1) {
                check = -1;
                break;
            }
        }
        scanf("%c", &c);
        if (c != '\n') {
            check = -1;
        }
    } else {
        check = 1;
    }
    return check;
}

void output(int **a, int n) {
    int p;
    for (p = 0; p < n - 1; p++) {
        printf("%d ", *(*a + p));
    }
    printf("%d", *(*a + p));
    free(*a);
}

void sort(int *a, int n) {
    for (int i = n - 1; i > 0; i--) {
        int max = a[0];
        int jMax = 0;
        for (int j = 0; j < i; j++) {
            if (max < a[j + 1]) {
                max = a[j + 1];
                jMax = j + 1;
            }
        }
        int temp = a[i];
        a[i] = max;
        a[jMax] = temp;
    }
}
