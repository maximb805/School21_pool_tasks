// Copyright 2022 gonalol
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        printf("n/a\n");
        return 1;
    }
    squaring(data, n);
    output(data, n);
    return 0;
}

int input(int *a, int * n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX || *n <= 0) {
        return -1;
    }
    int p;
    for (p = 0; p < *n - 1; p++) {
        if (scanf("%d%c", &a[p], &c) != 2 || c != ' ') {
            return -1;
        }
    }
    if (scanf("%d%c", &a[p], &c) != 2 || c != '\n') {
        return -1;
    }
    return 0;
}

void output(int *a, int n) {
    int p;
    for (p = 0; p < n - 1; p++) {
        printf("%d ", a[p]);
    }
    printf("%d\n", a[p]);
}

void squaring(int *a, int n) {
    for (int p = 0; p < n; p++) {
        a[p] *= a[p];
    }
}
