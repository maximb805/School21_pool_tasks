// Copyright 2022 gonzalol
#include "./data_process.h"
#include "../data_libs/data_io.h"

int main() {
    double *data;
    int n;
    if (scanf("%d", &n) == 1) {
        data = (double *) malloc(n * sizeof(double));
        input(data, n);

    if (normalization(data, n)) {
        output(data, n);
    } else {
        printf("ERROR");
    }
    free(data);
    }
    return 0;
}
