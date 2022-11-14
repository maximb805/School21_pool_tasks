// Copyright 2022 gonzalol
#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
int input(double *** matrix, int *i, int *j);
void output(double **matrix, int n, int m);
int input_params(int * rows, int * cols);
int fill_dynamic(double ** matrix, int i, int j);
void get_sorted_array(double ** matrix, int i,
                       int j, double * array);
void sort_array(int * array, int n);
void mem_alloc(double *** matrix, int i, int j);

int main() {
    double **matrix, **result;
    int n, m;

    int check = input(&matrix, &n, &m);
    if (check == 0) {
        printf("n/a");
    } else {
        if (check == 2) {
            printf("n/a");
        } else {
            
        }
        free(matrix);
    }
    return 0;
}

int input(double *** matrix, int *i, int *j) {
    int check = 0;
    if (input_params(i, j)) {
        *matrix = (double**)malloc(*i * (*j) * sizeof(double) +
                                sizeof(double*) * (*i));
        double * ptr = (double*)(*matrix + (*i));
        for (int p = 0; p < *i; p++) {
            *(*matrix + p) = ptr + ((*j) * p);
        }
        if (!fill_dynamic(*matrix, *i, *j)) {
            check = 2;
        } else {
            check = 1;
        }
    }
    return check;
}

int input_params(int * rows, int * cols) {
    int result = 1;
    if ((scanf("%d", rows) != 1 || *rows < 1)) {
        result = 0;
    }
    if (result != 0 && ((scanf("%d", cols) != 1 || *cols < 1))) {
        result = 0;
    }
    if (*rows != *cols) {
        result = 0;
    }
    return result;
}

int fill_dynamic(double ** matrix, int i, int j) {
    char c;
    int check = 1;
    for (int p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            if (check != 1 || scanf("%g", &matrix[p][k]) != 1) {
                check = 0;
                break;
            }
        }
    }
    scanf("%c", &c);
    if (c != '\n') {
        check = 0;
    }
    return check;
}

void output(double ** matrix, int i, int j) {
    for (int p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            printf("%g", matrix[p][k]);
            if (k < j - 1) {
                printf(" ");
                continue;
            }
            if (k == j - 1 && p < i - 1) {
                printf("\n");
            }
        }
    }
}

void get_sorted_array(double ** matrix, int i,
                       int j, double * array) {
    int n = 0;
    for (int p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            array[n] = matrix[p][k];
            n++;
        }
    }
    sort_array(array, n);
}

void sort_array(double * array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int index = 0;
        int j;
        for (j = 0; j <= i; j++) {
            if (array[index] < array[j]) {
                index = j;
            }
        }
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
}

void mem_alloc(double *** matrix, int i, int j) {
    *matrix = (int**)malloc(i * j * sizeof(double) +
                            sizeof(double*) * i);
    double * ptr = (double*)(*matrix + i);
    for (int p = 0; p < i; p++) {
        *(*matrix + p) = ptr + (j * p);
    }
}


