// Copyright 2022 gonalol
#include <stdio.h>
#define N 10

int input(int *a);
void output(int *a);
void sort(int *a);

int main() {
    int a[N];
    if (input(a) != 0) {
        printf("n/a\n");
        return 1;
    }
    sort(a);
    output(a);

    return 0;
}

int input(int *a) {
    char c;
    int p;
    for (p = 0; p < N - 1; p++) {
        if (scanf("%d%c", &a[p], &c) != 2 || c != ' ') {
            return -1;
        }
    }
    if (scanf("%d%c", &a[p], &c) != 2 || c != '\n') {
        return -1;
    }
    return 0;
}

void output(int *a) {
    int p;
    for (p = 0; p < N - 1; p++) {
        printf("%d ", a[p]);
    }
    printf("%d\n", a[p]);
}

void sort(int *a) {
    for (int i = N - 1; i > 0; i--) {
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
