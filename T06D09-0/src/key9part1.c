// Copyright 2022 gonzalol
/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length,
                 int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() {
    int n, a[NMAX], numbers[NMAX];
    if (input(a, &n) != 0) {
        printf("n/a\n");
    } else {
        int sum = sum_numbers(a, n);
        printf("%d\n", sum);
        int count = find_numbers(a, n, sum, numbers);
        output(numbers, count);
    }
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

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length,
                 int number, int* numbers) {
    int j = 0, count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[j++] = buffer[i];
            count++;
        }
    }
    return count;
}
