/**
 * @file polynomial.cpp
 * @author Wuwei YUAN
 * @date 3/4/2020
 * Definition of functions for computing polynomial
 */

#include "func.h"

double BruteForceComputePolynomialFunction(const std::vector<double> &a, const double &x) {
  int n = a.size();
  double result = 0;
  for (int i = 0; i < n; i++) {
    // Compute x^i
    double x_i = 1;
    for (int j = 1; j <= i; j++) {
      x_i *= x;
    }
    result += a[i] * x_i;
  }
  return result;
}

double QingjiushaosComputePolynomialFunction(const std::vector<double> &a, const double &x) {
  int n = a.size();
  double result = 0;
  for (int i = n - 1; i >= 0; i--) {
    result = result * x + a[i];
  }
  return result;
}
