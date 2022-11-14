// Copyright 2022 gonalol
#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
double sigma(int * a, int n);
void get_result(int * a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        printf("n/a\n");
        return 1;
    }
    get_result(data, n);
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

double mean(int *a, int n) {
    double mean_v = 0;
    for (int p = 0; p < n; p++) {
        mean_v += 1.0/n * a[p];
    }
    return mean_v;
}

double variance(int *a, int n) {
    double mean_v = mean(a, n);
    double variance_v = -(mean_v * mean_v);
    for (int p = 0; p < n; p++) {
        variance_v += 1.0/n * a[p] * a[p];
    }
    return variance_v;
}

double sigma(int * a, int n) {
    return sqrt(variance(a, n));
}

void get_result(int * a, int n) {
    double tr_si = sigma(a, n) * 3;
    double mean_v = mean(a, n);
    for (int p = 0; p < n; p++) {
        if (a[p] % 2 == 0 && a[p] >= mean_v &&
            a[p] <= (mean_v + tr_si) && a[p] != 0) {
            printf("%d\n", a[p]);
            return;
        }
    }
    printf("0\n");
}
