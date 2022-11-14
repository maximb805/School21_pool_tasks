// Copyright 2022 gonalol
#include <stdio.h>
#define N 10

int input(int *a);
void output(int *a);
void qSort(int *a, int left, int right);
void swap(int * a, int i, int j);
int medianOf3(int * a, int left, int right);
int partition(int * a, int left, int right, int num);

int main() {
    int a[N];
    if (input(a) != 0) {
        printf("n/a\n");
        return 1;
    }
    qSort(a, 0, N - 1);
    output(a);

    return 0;
}

int input(int *a) {
    char c;
    int p;
    for (p = 0; p < N - 1; p++) {
        if (scanf("%d%c", &a[p], &c) != 2 || c != ' ') {
            printf("p = %d", p);
            return -1;
        }
    }
    if (scanf("%d%c", &a[p], &c) != 2 || c != '\n') {
        return -1;
    }
    return 0;
}

void output(int *a) {
    int p;
    for (p = 0; p < N - 1; p++) {
        printf("%d ", a[p]);
    }
    printf("%d\n", a[p]);
}

void qSort(int *a, int left, int right) {
    if (left < right) {
        if (right - left > 2) {
            int med = medianOf3(a, left, right);
            int part = partition(a, left, right, med);
            qSort(a, left, part - 1);
            qSort(a, part + 1, right);
        } else {
            if (a[left] > a[right]) {
                swap(a, left, right);
            }
        }
    }
}

int medianOf3(int * a, int left, int right) {
    int med = (left + right) / 2;
    if (a[left] > a[med]) {
        swap(a, left, med);
    }
    if (a[left] > a[right]) {
        swap(a, left, right);
    }
    if (a[med] > a[right]) {
        swap(a, med, right);
    }
    swap(a, med, right - 1);
    return a[right - 1];
}

void swap(int * a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int * a, int left, int right, int num) {
    int leftB = left + 1;
    int rightB = right - 1;
    while(1) {
        while (a[leftB] < num && rightB > leftB) {
            leftB++;
        }
        while (a[rightB] >= num && rightB > leftB) {
            rightB--;
        }
        if (leftB < rightB) {
            swap(a, leftB, rightB);
        } else {
            break;
        }
    }
    swap(a, leftB, right - 1);
    return leftB;
}
