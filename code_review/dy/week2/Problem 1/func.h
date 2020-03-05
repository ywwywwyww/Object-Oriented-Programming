/**
 * @file				func.h
 * @author				Yan DAI
 * @date				Feb 26, 2020
 *
 * Define the functions used.
 */

#ifndef __FUNC_H__
#define __FUNC_H__

#include <vector>

constexpr double eps = 1e-7; // Epsilon for comparing doubles

double calc_polynomial(const std::vector<double> &coef,
					   double x, bool use_qin);
double calc_posynomial(const std::vector<double> &coef,
					   double x, bool use_qin);

#endif
