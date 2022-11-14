// Copyright 2022 gonzalol
#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int * max, int * min);

/* Find a max & min probabilities */
int main() {
    int x, y, z;
    char c;
    if (scanf("%d%d%d%c", &x, &y, &z, &c) != 4 || c != '\n') {
        printf("n/a\n");
        return 1;
    }
    int max, min;
    maxmin(x, y, z, &max, &min);
    printf("%d %d\n", max, min);
    return 0;
}

/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int * max, int * min) {
    *max = *min = prob1;
    if (prob2 > *max) {
        *max = prob2;
    }
    if (prob2 < *min) {
        *min = prob2;
    }
    if (prob3 > *max) {
        *max = prob3;
    }
    if (prob3 < *min) {
        *min = prob3;
    }
}

