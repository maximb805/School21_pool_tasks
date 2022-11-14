// Copyright 2022 gonzalol
#include <stdio.h>
#include <stdlib.h>
#define MAX_I 100
#define MAX_J 100

int getArray(int * i, int * j);
void output_static(int i, int j, int a[][j]);
void output_dynamic(int ** matrix, int i, int j);
int input_params(int * malloctype, int * cols, int * rows);
int fill_static(int i, int j, int a[][j]);
int get_dynamic_1(int i, int j);
int get_dynamic_2(int i, int j);
int get_dynamic_3(int i, int j);
int fill_dynamic(int ** matrix, int i, int j);
void min_max_output_dyn(int ** matrix, int * max, int * min, int i, int j);
void output_arr(int * max, int * min, int i, int j);
void min_max_output_static(int * max, int * min, int i, int j, int matrix[][j]);

int main() {
    int i , j;
    if (getArray(&i, &j) != 0) {
        printf("n/a");
    }
    return 0;
}

int getArray(int * i, int * j) {
    int malloctype, check = 1;
    if (!input_params(&malloctype, i, j)) {
        switch (malloctype) {
            case 1 : {
                if (*i > MAX_I || *j > MAX_J || *i < 1 || *j < 1) {
                    check = 1;
                } else {
                    int arr[*i][*j];
                    if (!fill_static(*i, *j, arr)) {
                        check = 0;
                    } else {
                        check = 1;
                    }
                }
                break;
            }
            case 2 : {
                if (get_dynamic_1(*i, *j)) {
                    check = 1;
                } else {
                    check = 0;
                }
                break;
            }
            case 3 : {
                if (get_dynamic_2(*i, *j)) {
                    check = 1;
                } else {
                    check = 0;
                }
                break;
            }
            case 4 : {
                if (get_dynamic_3(*i, *j)) {
                    check = 1;
                } else {
                    check = 0;
                }
                break;
          }
            default : check = 1;
        }
    }
    return check;
}

int input_params(int * malloctype, int * rows, int * cols) {
    int result = 0;
    if (scanf("%d", malloctype) != 1 || *malloctype < 1 || *malloctype > 4) {
        result = 1;
    }
    if (result != 1 && (scanf("%d", rows) != 1 || *rows < 1)) {
        result = 1;
    }
    if (result != 1 && (scanf("%d", cols) != 1 || *cols < 1)) {
        result = 1;
    }
    return result;
}

void output_static(int i, int j, int a[i][j]) {
    int p;
    for (p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            if (k == j - 1) {
                printf("%d\n", a[p][k]);
            } else {
                printf("%d ", a[p][k]);
            }
        }
    }
}

void output_dynamic(int ** matrix, int i, int j) {
    int p;
    for (p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            if (k == j - 1) {
                printf("%d\n", matrix[p][k]);
            } else {
                printf("%d ", matrix[p][k]);
            }
        }
    }
}

int fill_static(int i, int j, int a[i][j]) {
    char c;
    int check = 0;
    for (int p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            if (check != 0 ||scanf("%d", &a[p][k]) != 1) {
                check = 1;
            }
        }
    }
    scanf("%c", &c);
    if (c != '\n') {
        check = 1;
    }
    if (check == 0) {
        int min[MAX_I];
        int max[MAX_J];
        output_static(i, j, a);
        min_max_output_static(max, min, i, j, a);
    }
    return check;
}

int get_dynamic_1(int i, int j) {
    int check = 0;
    int ** matrix = malloc(i * j * sizeof(int) + sizeof(int*) * i);
    int * ptr = (int*)(matrix + i);
    for (int p = 0; p < i; p++) {
        matrix[p] = ptr + i * p;
    }
    if (fill_dynamic(matrix, i, j)) {
        check = 1;
    } else {
        int min;
        int max;
        output_dynamic(matrix, i, j);
        min_max_output_dyn(matrix, &max, &min, i, j);
    }
    free(matrix);
    return check;
}

int get_dynamic_2(int i, int j) {
    int check = 0;
    int ** pointer_array = malloc(i * sizeof(int*));
    for (int p = 0; p < i; p++) {
        pointer_array[p] = malloc(j * sizeof(int));
    }
    if (fill_dynamic(pointer_array, i, j)) {
        check = 1;
    } else {
        int min;
        int max;
        output_dynamic(pointer_array, i, j);
        min_max_output_dyn(pointer_array, &max, &min, i, j);
    }
    for (int p = 0; p < i; p++) {
        free(pointer_array[p]);
    }
    free(pointer_array);
    return check;
}

int get_dynamic_3(int i, int j) {
    int check = 0;
    int ** pointer_array = malloc(i * sizeof(int*));
    int * array = malloc(i * j * sizeof(int));
    for (int p = 0; p < i; p++) {
        pointer_array[p] = array + (j * p);
    }
    if (fill_dynamic(pointer_array, i, j)) {
        check = 1;
    } else {
        int min;
        int max;
        output_dynamic(pointer_array, i, j);
        min_max_output_dyn(pointer_array, &max, &min, i, j);
    }
    free(pointer_array);
    free(array);
    return check;
}

int fill_dynamic(int ** matrix, int i, int j) {
    char c;
    int check = 0;
    for (int p = 0; p < i; p++) {
        for (int k = 0; k < j; k++) {
            if (check != 0 || scanf("%d", &matrix[p][k]) != 1) {
                check = 1;
                break;
            }
        }
    }
    scanf("%c", &c);
    if (c != '\n') {
        check = 1;
    }
    return check;
}

void min_max_output_static(int * max, int * min, int i, int j, int matrix[][j]) {
    for (int p = 0; p < i; p++) {
        max[p] = matrix[p][0];
        for (int k = 0; k < j; k++) {
            if (max[p] < matrix[p][k])
                max[p] = matrix[p][k];
        }
    }
    for (int k = 0; k < j; k++) {
        min[k] = matrix[0][k];
        for (int p = 0; p < i; p++) {
            if (min[k] > matrix[p][k])
                min[k] = matrix[p][k];
        }
    }
    output_arr(max, min, i, j);
}

void min_max_output_dyn(int ** matrix, int * max, int * min, int i, int j) {
    max = malloc(sizeof(int) * i);
    min = malloc(sizeof(int) * j);
    for (int p = 0; p < i; p++) {
        max[p] = matrix[p][0];
        for (int k = 0; k < j; k++) {
            if (max[p] < matrix[p][k])
                max[p] = matrix[p][k];
        }
    }
    for (int k = 0; k < j; k++) {
        min[k] = matrix[0][k];
        for (int p = 0; p < i; p++) {
            if (min[k] > matrix[p][k])
                min[k] = matrix[p][k];
        }
    }
    output_arr(max, min, i, j);
    free(max);
    free(min);
}

void output_arr(int * max, int * min, int i, int j) {
    for (int p = 0; p < i - 1; p++) {
        printf("%d ", max[p]);
    }
    printf("%d\n", max[i - 1]);
    for (int p = 0; p < j - 1; p++) {
        printf("%d ", min[p]);
    }
    printf("%d", min[j - 1]);
}
