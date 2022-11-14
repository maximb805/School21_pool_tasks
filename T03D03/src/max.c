// Copyright 2022 gonzalol
#include <stdio.h>

int max(int a, int b);

int main() {
  int a, checkScan, checkNum;
  float b;

  checkScan = scanf("%i %f", &a, &b);
  checkNum = b;

  if (checkScan == 2 && (b / checkNum) == 1.0) {
    printf("%d\n", max(a, b));
  } else {
    printf("n/a\n");
  }
  return 0;
}

int max(int a, int b) {
  return a > b ? a : b;
}

