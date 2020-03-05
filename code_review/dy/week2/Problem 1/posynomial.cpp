/**
 * @file				posynomial.cpp
 * @author				Yan DAI
 * @date				Feb 26, 2020
 *
 * Implements posynomial calculating.
 */

#include "func.h"

#include <cmath> // For `fabs()` function.

/**
 * Calculating posynomial f(x) = Sum ai * x^{-i}, i = 0 .. n-1.
 * @param  coef    The coefficient vector (a).
 * @param  x       The parameter x.
 * @param  use_qin Whether to use Qin Jiushao algorithm.
 * @return         The result.
 */
double calc_posynomial(const std::vector<double> &coef,
					   double x, bool use_qin)
{
	int n = coef.size();
	double result = 0;
	if (fabs(x) <= eps)
	{
		// x is zero, so do nothing in this case
	}
	else if (!use_qin)
	{
		for (int i = 0; i < n; i++)
		{
			double current = coef[i]; // a[i] / x^i
			for (int j = 0; j < i; j++)
				current /= x;
			result += current;
		}
	}
	else
	{
		for (int i = n - 1; i >= 0; i--)
			result = result / x + coef[i];
	}
	return result;
}
