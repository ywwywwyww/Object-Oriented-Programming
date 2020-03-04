//
// Created by yww on 3/3/20.
//

#include <cmath>
#include <iostream>
#include "func.h"

double BruteForceComputePosynomialFunction(const double *a, const int &n, const double &x) {
  if (fabs(x) < 1e-9) {
    std::cerr << "ERROR illegal input: x is zero\n";
    return nan("");
  }
  double inverse_x = 1 / x;
  double result = 0;
  for (int i = 0; i < n; i++) {
    double temp_x_n = 1;
    for (int j = 1; j <= i; j++) {
      temp_x_n *= inverse_x;
    }
    result += a[i] * temp_x_n;
  }
  return result;
}

double QingjiushaosComputePosynomialFunction(const double *a, const int &n, const double &x) {
  if (fabs(x) < 1e-9) {
    std::cerr << "ERROR illegal input: x is zero\n";
    return nan("");
  }
  double inverse_x = 1 / x;
  double result = 0;
  for (int i = n - 1; i >= 0; i--) {
    result = result * inverse_x + a[i];
  }
  return result;
}
