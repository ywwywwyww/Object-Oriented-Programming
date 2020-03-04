/**
 * @file func.h
 * @author Wuwei YUAN
 * @date 3/4/2020
 * Declaration of functions for computing polynomial and posynomial
 */

#ifndef PROBLEM1_FUNC_H
#define PROBLEM1_FUNC_H

/**
 * Computes polynomial function by brute force algorithm
 * @param a The coefficients
 * @param n The degree of polynomial
 * @param x The value of independent variable
 * @return The value of polynomial
 */
double BruteForceComputePolynomialFunction(const double *a, const int &n, const double &x);

/**
 * Computes polynomial function by QINGJiuShao's algorithm
 * @param a The coefficients
 * @param n The degree of polynomial
 * @param x The value of independent variable
 * @return The value of polynomial
 */
double QingjiushaosComputePolynomialFunction(const double *a, const int &n, const double &x);

/**
 * Computes posynomial function by brute force algorithm
 * @param a The coefficients
 * @param n The degree of posynomial
 * @param x The value of independent variable
 * @return The value of posynomial
 */
double BruteForceComputePosynomialFunction(const double *a, const int &n, const double &x);

/**
 * Compute posynomial function by QINGJiuShao's algorithm
 * @param a The coefficients
 * @param n The degree of posynomial
 * @param x The value of independent variable
 * @return The value of posynomial
 */
double QingjiushaosComputePosynomialFunction(const double *a, const int &n, const double &x);

#endif //PROBLEM1_FUNC_H
