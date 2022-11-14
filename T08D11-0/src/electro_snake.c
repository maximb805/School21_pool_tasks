// Copyright 2022 gonzalol
#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int i, int j, int ***result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int i, int j, int ***result_matrix);


int input(int *** matrix, int *i, int *j);
void output(int **matrix, int n, int m);
int input_params(int * rows, int * cols);
int fill_dynamic(int ** matrix, int i, int j);
void get_sorted_array(int ** matrix, int i,
                       int j, int * array);
void sort_array(int * array, int n);
void mem_alloc(int *** matrix, int i, int j);

int main() {
    int **matrix, **result;
    int n, m;

    int check = input(&matrix, &n, &m);
    if (check == 0) {
        printf("n/a");
    } else {
        if (check == 2) {
            printf("n/a");
        } else {
            sort_vertical(matrix, n, m, &result);
            output(result, n, m);
            printf("\n");
            printf("\n");
            free(result);
            sort_horizontal(matrix, n, m, &result);
            output(result, n, m);
            free(result);
        }
        free(matrix);
    }
    return 0;
}

int input(int *** matrix, int *i, int *j) {
    int check = 0;
    if (input_params(i, j)) {
        *matrix = (int**)malloc(*i * (*j) * sizeof(int) +
                                sizeof(int*) * (*i));
        int * ptr = (int*)(*matrix + (*i));
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
    return result;
}

int fill_dynamic(int ** matrix, int i, int j) {
    char c;
    int check = 1;
    for (int p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            if (check != 1 || scanf("%d", &matrix[p][k]) != 1) {
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

void output(int ** matrix, int i, int j) {
    for (int p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            printf("%d", matrix[p][k]);
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

void sort_horizontal(int ** matrix, int i,
                     int j, int ***result) {
    int * array = malloc(i * j * sizeof(int));
    get_sorted_array(matrix, i, j, array);
    int n = 0, k = 0;
    mem_alloc(result, i, j);
    while (n < j * i) {
        for (int p = 0; p < j; p++, n++) {
            *(*(*result + k) + p) = array[n];
        }
        k++;
        if (n >= j * i) {
            break;
        }
        for (int p = j - 1; p >= 0; p--, n++) {
            *(*(*result + k) + p) = array[n];
        }
        k++;
    }
    free(array);
}

void sort_vertical(int ** matrix, int i,
                     int j, int ***result) {
    int * array = malloc(i * j * sizeof(int));
    get_sorted_array(matrix, i, j, array);
    int n = 0, k = 0;
    mem_alloc(result, i, j);
    while (n < j * i) {
        for (int p = 0; p < i; p++, n++) {
            *(*(*result + p) + k) = array[n];
        }
        k++;
        if (n >= j * i) {
            break;
        }
        for (int p = i - 1; p >= 0; p--, n++) {
            *(*(*result + p) + k) = array[n];
        }
        k++;
    }
    free(array);
}

void get_sorted_array(int ** matrix, int i,
                       int j, int * array) {
    int n = 0;
    for (int p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            array[n] = matrix[p][k];
            n++;
        }
    }
    sort_array(array, n);
}

void sort_array(int * array, int n) {
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

void mem_alloc(int *** matrix, int i, int j) {
    *matrix = (int**)malloc(i * j * sizeof(int) +
                            sizeof(int*) * i);
    int * ptr = (int*)(*matrix + i);
    for (int p = 0; p < i; p++) {
        *(*matrix + p) = ptr + (j * p);
    }
}
