// Copyright 2022 gonzalol
#include <stdio.h>
#include <math.h>

double anyez(double n);

double bern(double n);

double quadr(double n);

int main() {
  const double negPi = -3.14159265358979323846;
  const double step = negPi * -2 / 41;
  int i = 42;
  double num = negPi;
  while (i > 0) {
    double bernSol = bern(num);
    if (bernSol == -1.0) {
        printf("%.7f | %.7f | - | %.7f\n", num, anyez(num), quadr(num));
    } else {
        printf("%.7f | %.7f | %.7f | %.7f\n", num, anyez(num),
          bern(num), quadr(num));
    }
    num = num + step;
    i--;
  }
}

double anyez(double n) {
  return 1 / (1 + (n * n));
}

double bern(double n) {
  double firstSqrt = sqrt((1 + (4 * n * n))) - (n * n) - 1;
  if (firstSqrt < 0) {
      return -1.0;
  }
  return sqrt(firstSqrt);
}

double quadr(double n) {
  return 1 / (n * n);
}
