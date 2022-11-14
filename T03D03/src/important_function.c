// Copyright 2022 gonzalol
#include <stdio.h>
#include <math.h>

int max(int a, int b);

int main() {
  float x;
  if (scanf("%f", &x) == 1) {
  double y = (7e-3 * pow(x, 4)) + (((22.8 * pow(x, (1 / 3))) - 1e+3) * x + 3) /
      ((x * x) / 2) - (x * pow((10 + x), (2 / x))) - 1.01;
  printf("%.1f\n", y);
  } else {
    printf("n/a\n");
  }
  return 0;
}

int max(int a, int b) {
  return a > b ? a : b;
}

