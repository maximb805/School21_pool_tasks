// Copyright 2022 gonzalol
#include <stdio.h>
#define LEN 100


int input(int *a, int * b, int * la, int * lb);
void output(int *a, int n);
void sum(int *buff1, int len1, int *buff2, int len2,
         int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2,
         int *result, int *result_length);
int compare(int * a, int la, int * b, int lb);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

int main() {
    int la = 0, lb = 0, a[LEN], b[LEN], result_sum[LEN],
        result_sum_l, result_sub[LEN], result_sub_l;
    if (input(a, b, &la, &lb) != 0) {
        printf("n/a\n");
    } else {
        result_sum_l = la > lb ? la + 1 : lb + 1;
        sum(a, la, b, lb, result_sum, &result_sum_l);
        output(result_sum, result_sum_l);
        if (compare(a, la, b, lb)) {
            result_sub_l = la;
            sub(a, la, b, lb, result_sub, &result_sub_l);
            output(result_sub, result_sub_l);
        } else {
            printf("n/a\n");
        }
    }
    return 0;
}

int input(int *a, int * b, int * la, int * lb) {
    char ch = ' ';
    while (ch != '\n') {
        if (scanf("%d%c", &a[*la], &ch) != 2 ||
            (ch != ' ' && ch != '\n') || *la >= LEN ||
            a[*la] < 0 || a[*la] > 9) {
            return -1;
        }
        *la += 1;
    }
    ch = ' ';
    while (ch != '\n') {
        if (scanf("%d%c", &b[*lb], &ch) != 2 ||
            (ch != ' ' && ch != '\n') || *lb >= LEN ||
            b[*lb] < 0 || b[*lb] > 9) {
            return -1;
        }
        *lb = *lb + 1;
    }
    return 0;
}

void output(int *a, int n) {
    int p = 0;
    while (a[p] == 0 && p < n - 1) {
        p++;
    }
    for ( ; p < n - 1; p++) {
        printf("%d ", a[p]);
    }
    printf("%d\n", a[p]);
}

void sum(int *buff1, int len1, int *buff2, int len2,
         int *result, int *result_length) {
    int maxlen, minlen;
    int * arr_max, * arr_min;
    if (len2 < len1) {
        maxlen = len1;
        minlen = len2;
        arr_max = buff1;
        arr_min = buff2;
    } else {
        maxlen = len2;
        minlen = len1;
        arr_max = buff2;
        arr_min = buff1;
    }
    for (int i = 1; i <= maxlen; i++) {
        if (minlen - i >= 0) {
            result[*result_length - i] = arr_max[maxlen - i] +
            arr_min[minlen - i];
        } else {
            result[*result_length - i] = arr_max[maxlen - i];
        }
    }
    for (int i = *result_length - 1; i > 0; i--) {
        if (result[i] > 9) {
            result[i] -= 10;
            result[i - 1] += 1;
        }
    }
}

void sub(int *buff1, int len1, int *buff2, int len2,
         int *result, int *result_length) {
    for (int i = 1; i <= len1; i++) {
        if (len2 - i >= 0) {
            result[*result_length - i] = buff1[len1 - i] - buff2[len2 - i];
        } else {
            result[*result_length - i] = buff1[len1 - i];
        }
    }
    for (int i = *result_length - 1; i > 0; i--) {
        if (result[i] < 0) {
            result[i] += 10;
            result[i - 1] -= 1;
        }
    }
}

int compare(int * a, int la, int * b, int lb) {
    int result = 0;
    if (la >= lb) {
        if (la == lb) {
            for (int i = 0; i < la; i++) {
                if (a[i] > b[i]) {
                    result = 1;
                    break;
                }
                if (a[i] < b[i]) {
                    result = 0;
                    break;
                }
                result = 1;
            }
        } else {
            result = 1;
        }
    }
    return result;
}
