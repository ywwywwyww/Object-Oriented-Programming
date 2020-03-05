/**
 * @file				main.cpp
 * @author				Yan DAI
 * @date				Feb 26, 2020
 */

/**
 * Personally, I perfer snake_case to camelCase,
 * as it's more 'like' a C/C++ code or header.
 *
 * I also perfer Allman (bracket) style to K&R style,
 * as it shows the border of a block more clearly.
 */

#include "timer.h"

#include "func.h"
#include <vector>

#include <iostream> // For outputing result.
#include <cstdlib> // For `atoi()` and `atof()` functions.
#include <cmath> // For `fabs()` function.

/**
 * Calculate improvement from `baseline` to `time`.
 */
double calc_improvement(double time, double baseline)
{
	return (baseline - time) / baseline;
}

int main(int argc, char **argv)
{
	int n = argc - 2;
	std::vector<double> coef(n);
	for (int i = 1; i <= n; i++)
		coef[i - 1] = atof(argv[i]);
	double x = atof(argv[n + 1]);

	Timer timer_poly, timer_poly_qin,
		  timer_posy, timer_posy_qin;
	double res_poly = 0, res_poly_qin = 0,
		   res_posy = 0, res_posy_qin = 0;
	constexpr int time_repeat = 10'000;
	for (int i = 0; i < time_repeat; i++)
	{
		for (int j = 0; j < time_repeat; j++)
		{
			timer_poly.start();
			res_poly = calc_polynomial(coef, x, false);
			timer_poly.stop();

			timer_poly_qin.start();
			res_poly_qin = calc_polynomial(coef, x, true);
			timer_poly_qin.stop();

			timer_posy.start();
			res_posy = calc_posynomial(coef, x, false);
			timer_posy.stop();

			timer_posy_qin.start();
			res_posy_qin = calc_posynomial(coef, x, true);
			timer_posy_qin.stop();

			assert(fabs(res_poly - res_poly_qin) <= eps);
			assert(fabs(res_posy - res_posy_qin) <= eps);
		}
	}

	std::cout << "Result for polynomial is: " << res_poly << std::endl;
	std::cout << "Time usage when not using Qin algorithm: " <<
			  timer_poly.time() << " seconds" << std::endl;
	std::cout << "Time usage when using Qin algorithm: " <<
			  timer_poly_qin.time() << " seconds" << std::endl;
	std::cout << "Improvement: " << calc_improvement(timer_poly_qin.time(),
			  timer_poly.time()) << std::endl << std::endl;

	if (fabs(x) <= eps)
	{
		std::cout << "x is zero, so posynomial is not calculated." << std::endl;
		return 0;
	}
	std::cout << "Result for posynomial is: " << res_posy << std::endl;
	std::cout << "Time usage when not using Qin algorithm: " <<
			  timer_posy.time() << " seconds" << std::endl;
	std::cout << "Time usage when using Qin algorithm: " <<
			  timer_posy_qin.time() << " seconds" << std::endl;
	std::cout << "Improvement: " << calc_improvement(timer_posy_qin.time(),
			  timer_posy.time()) << std::endl;
	return 0;
}
