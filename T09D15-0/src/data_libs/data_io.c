// Copyright 2022 gonzalol
#ifndef DATA_IO_C
#define DATA_IO_C
#include "./data_io.h"

void input(double * data, int n) {
    for (int p = 0; p < n; p++) {
        if (scanf("%lf", &data[p]) != 1) {
            break;
        }
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%.2f ", data[i]);
    }
    printf("%.2f", data[n - 1]);
}

#endif
