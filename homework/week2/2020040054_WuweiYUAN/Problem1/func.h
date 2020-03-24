/**
 * @file func.h
 * @author Wuwei YUAN
 * @date 3/4/2020
 * Declaration of functions for computing polynomial and posynomial
 */

#ifndef PROBLEM1_FUNC_H
#define PROBLEM1_FUNC_H

#include <vector>

namespace brute_force {

/**
 * Computes polynomial function by brute force algorithm
 * @param a The coefficients
 * @param x The value of independent variable
 * @return The value of polynomial
 */
double ComputePolynomialFunction(const std::vector<double> &a, const double &x);

/**
 * Computes posynomial function by brute force algorithm
 * @param a The coefficients
 * @param x The value of independent variable
 * @return The value of posynomial
 */
double ComputePosynomialFunction(const std::vector<double> &a, const double &x);

} // namespace brute_force

namespace qingjiushao {

/**
 * Computes polynomial function by QINGJiuShao's algorithm
 * @param a The coefficients
 * @param x The value of independent variable
 * @return The value of polynomial
 */
double ComputePolynomialFunction(const std::vector<double> &a, const double &x);

/**
 * Computes posynomial function by QINGJiuShao's algorithm
 * @param a The coefficients
 * @param x The value of independent variable
 * @return The value of posynomial
 */
double ComputePosynomialFunction(const std::vector<double> &a, const double &x);

} // namespace qingjiushao

#endif //PROBLEM1_FUNC_H
