// Copyright 2022 gonzalol
#include <stdio.h>
#include <math.h>

int isPrime(int a);

int divides(int a, int b);

int main() {
  float x;
  int ch = scanf("%f", &x);
  if (ch != 1 || (int)x != x) {
    printf("n/a\n");
    return 1;
  }
  if (x < 0) {
    x = x * -1;
  }
  int a = (int) x;
  int bin = 1;
  int y = a - 1;
  int check = a <= 1 ? 0 : 1;

  while (check) {
    if (((int)(a * 0.5) == (a * 0.5) && a != 2) || bin != 1) {
      y = (int)(y * 0.5) == (y * 0.5) && y != 2 ? y - 1 : y;
      while (y > 1) {
        if (divides(a, y)) {
          if (isPrime(y)) {
            printf("%d\n", y);
            break;
          }
        }
        y = y - 2;
        if (y == 1) {
          if (divides(a, 2)) {
            printf("%d\n", 2);
            break;
          } else {
            printf("n/a\n");
            break;
          }
        }
      }
      break;
    } else {
      if (isPrime(a)) {
        printf("%d\n", a);
        break;
      } else {
        bin = 0;
      }
    }
  }
  return 0;
}

int divides(int a, int b) {
  while (a >= b) {
    a = a - b;
  }
  return a == 0 ? 1 : 0;
}

int isPrime(int a) {
  if ((((int)(a * 0.5) == (a * 0.5)) && a != 2) || a <= 1) {
    return 0;
  } else {
    int sqr = (int)sqrt(a) + 1;
    while (sqr > 1) {
      if (divides(a, sqr)) {
        return 0;
      } else {
        sqr = sqr - 1;
      }
    }
  }
  return 1;
}
