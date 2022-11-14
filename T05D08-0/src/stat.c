// Copyright 2022 gonalol
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        printf("n/a\n");
        return 1;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

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

int max(int *a, int n) {
    int max_v = a[0];
    for (int p = 1; p < n; p++) {
        max_v = a[p] > max_v ? a[p] : max_v;
    }
    return max_v;
}

int min(int *a, int n) {
    int min_v = a[0];
    for (int p = 1; p < n; p++) {
        min_v = a[p] < min_v ? a[p] : min_v;
    }
    return min_v;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f\n", max_v, min_v, mean_v, variance_v);
}
