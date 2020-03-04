//
// Created by yww on 3/3/20.
//

#include "func.h"

double BruteForceComputePolynomialFunction(const double *a, const int &n, const double &x) {
  double result = 0;
  for (int i = 0; i < n; i++) {
    double temp_x_i = 1;
    for (int j = 1; j <= i; j++) {
      temp_x_i *= x;
    }
    result += a[i] * temp_x_i;
  }
  return result;
}

double QingjiushaosComputePolynomialFunction(const double *a, const int &n, const double &x) {
  double result = 0;
  for (int i = n - 1; i >= 0; i--) {
    result = result * x + a[i];
  }
  return result;
}
