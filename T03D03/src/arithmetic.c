// Copyright 2022 gonzalol
#include <stdio.h>

int sum(int a, int b);

int diff(int a, int b);

int mult(int a, int b);

int div(int a, int b);

int main() {
  int a, checkScan, checkNum;
  float b;

  checkScan = scanf("%i %f", &a, &b);
  checkNum = b;

  if (checkScan == 2 && (b / checkNum) == 1.0) {
    if (b != 0) {
      printf("%d %d %d %d\n", sum(a, b), diff(a, b), mult(a, b), div(a, b));
    } else {
      printf("%d %d %d n/a\n", sum(a, b), diff(a, b), mult(a, b));
    }
  } else {
    printf("n/a n/a n/a n/a\n");
  }
  return 0;
}

int sum(int a, int b) {
  return a + b;
}

int diff(int a, int b) {
  return a - b;
}

int mult(int a, int b) {
  return a * b;
}

int div(int a, int b) {
  return a / b;
}

