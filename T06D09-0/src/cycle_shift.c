// Copyright 2022 gonzalol
#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int * c);
void output(int *buffer, int length);
void cyclic_shift(int * buffer, int length, int c);

int main() {
    int n, a[NMAX], c;
    if (input(a, &n, &c) != 0) {
        printf("n/a\n");
    } else {
        cyclic_shift(a, n, c);
        output(a, n);
    }
    return 0;
}

int input(int *a, int * n, int * c) {
    char ch;
    char result = 0;
    if (scanf("%d%c", n, &ch) != 2 || ch != '\n' || *n > NMAX || *n <= 0) {
        result = -1;
    }
    if (result == 0) {
        int p;
        for (p = 0; p < *n - 1; p++) {
            if (scanf("%d%c", &a[p], &ch) != 2 || ch != ' ') {
                result = -1;
                break;
            }
        }
        if (result == 0) {
            if (scanf("%d%c", &a[p], &ch) != 2 || ch != '\n') {
                return -1;
            }
            if (scanf("%d%c", c, &ch) != 2 || ch != '\n') {
                result = -1;
            }
        }
    }
    return result;
}

void output(int *a, int n) {
    int p;
    for (p = 0; p < n - 1; p++) {
        printf("%d ", a[p]);
    }
    printf("%d\n", a[p]);
}

void cyclic_shift(int * buffer, int length, int c) {
    if (c > 0) {
        for (int i = 0; i < c; i++) {
            int temp = buffer[0];
            for (int j = 0; j < length - 1; j++) {
                buffer[j] = buffer[j + 1];
            }
            buffer[length - 1] = temp;
        }
    } else {
        c = c * -1;
        for (int i = 0; i < c; i++) {
            int temp = buffer[length - 1];
            for (int j = length - 1; j > 0; j--) {
                buffer[j] = buffer[j - 1];
            }
            buffer[0] = temp;
        }
    }
}
