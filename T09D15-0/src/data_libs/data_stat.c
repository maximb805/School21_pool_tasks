// Copyright 2022 gonzalol
#ifndef DATA_STAT_C
#define DATA_STAT_C
#include "./data_stat.h"

double max(double *data, int n) {
    double max_v = data[0];
    for (int p = 1; p < n; p++) {
        max_v = data[p] > max_v ? data[p] : max_v;
    }
    return max_v;
}

double min(double *data, int n) {
    double min_v = data[0];
    for (int p = 1; p < n; p++) {
        min_v = data[p] < min_v ? data[p] : min_v;
    }
    return min_v;
}

double mean(double *data, int n) {
    double mean_v = 0;
    for (int p = 0; p < n; p++) {
        mean_v += 1.0/n * data[p];
    }
    return mean_v;
}

double variance(double *data, int n) {
    double mean_v = mean(data, n);
    double variance_v = -(mean_v * mean_v);
    for (int p = 0; p < n; p++) {
        variance_v += 1.0/n * data[p] * data[p];
    }
    return variance_v;
}
#endif
