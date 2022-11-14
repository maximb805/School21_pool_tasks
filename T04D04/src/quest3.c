// Copyright 2022 gonzalol
#include <stdio.h>

int getFibb(int count, int prev, int fib);

int main() {
  float x;
  int c = scanf("%f", &x);
  if ((int)x != x || c != 1 || x < 0) {
    printf("n/a\n");
    return 0;
  }
  printf("%d\n", getFibb(x, 0, 0));
  return 0;
}

int getFibb(int count, int prev, int fib) {
  if (count == 0) {
    return fib;
  }
  if (fib == 0) {
    fib = 1;
  } else {
    int temp = prev;
    prev = fib;
    fib = fib + temp;
  }
  count--;
  return getFibb(count, prev, fib);
}
