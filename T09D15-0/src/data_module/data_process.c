// Copyright 2022 gonzalol
#ifndef PROCESSING_C
#define PROCESSING_C
#include "./data_process.h"
#include "../data_libs/data_stat.h"
#include <math.h>
#include <stdio.h>

int normalization(double *data, int n) {
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;
    if (fabs(size) < EPS) {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    } else {
        result = 0;
    }
    return result;
}

void sort(double *data, int n) {
    for (int i = n - 1; i > 0; i--) {
        int index = 0;
        for (int j = 0; j <= i; j++) {
            if (data[index] < data[j]) {
                index = j;
            }
        }
        double temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }
}
#endif
