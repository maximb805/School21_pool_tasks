// Copyright 2022 gonzalol
#include <stdio.h>

int main() {
  float x, y;
  if (scanf("%f %f", &x, &y) == 2) {
    if ((x * x) + (y * y) <= 25) {
      printf("GOTCHA\n");
    } else {
      printf("MISS\n");
    }
  } else {
    printf("n/a\n");
  }
  return 0;
}
