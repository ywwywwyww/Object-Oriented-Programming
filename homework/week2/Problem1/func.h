//
// Created by yww on 3/3/20.
//

#ifndef PROBLEM1_FUNC_H
#define PROBLEM1_FUNC_H

/**
 * compute polynomial function by brute force algorithm
 * @param a the coefficients
 * @param n the degree of polynomial
 * @param x the value of independent variable
 * @return the value of polynomial
 */
double BruteForceComputePolynomialFunction(const double *a, const int &n, const double &x);

/**
 * compute polynomial function by QINGJiuShao's algorithm
 * @param a the coefficients
 * @param n the degree of polynomial
 * @param x the value of independent variable
 * @return the value of polynomial
 */
double QingjiushaosComputePolynomialFunction(const double *a, const int &n, const double &x);

/**
 * compute posynomial function by brute force algorithm
 * @param a the coefficients
 * @param n the degree of posynomial
 * @param x the value of independent variable
 * @return the value of posynomial
 */
double BruteForceComputePosynomialFunction(const double *a, const int &n, const double &x);

/**
 * compute posynomial function by QINGJiuShao's algorithm
 * @param a the coefficients
 * @param n the degree of posynomial
 * @param x the value of independent variable
 * @return the value of posynomial
 */
double QingjiushaosComputePosynomialFunction(const double *a, const int &n, const double &x);

#endif //PROBLEM1_FUNC_H
