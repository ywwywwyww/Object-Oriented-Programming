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

#include "sorter.h"
#include <vector>

#include <algorithm> // For `std::sort()` function.
#include <iostream> // For outputing.
#include <cassert> // For checking correctness.
#include <cstdlib> // For `rand()` and `atoi()` function.
#include <climits> // For `INT_MAX`.
#include <ctime> // For seeding `rand()` function.

/**
 * Calculate improvement from `baseline` to `time`.
 */
double calc_improvement(double time, double baseline)
{
	return (baseline - time) / baseline;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./sorter <length of tested array>" << std::endl;
		return -1;
	}

	// Generate the random array to be tested.
	srand(time(NULL));
	int len = atoi(argv[1]);
	std::vector<int> arr(len);
	for (int i = 0; i < len; i++)
		arr[i] = generate_random(0, INT_MAX);

	// Generate the correct result by using `std::sort`
	auto answer = arr;
	std::sort(answer.begin(), answer.end());

	Timer timer;
	Sorter sorter;
	double time_bubble_sort = 0,
		   time_quick_sort = 0,
		   time_merge_sort = 0;

	/**
	 * These duplicate codes can be greatly simplified by
	 * defining macros, but it's not so OOP-style.
	 *
	 * One more OOP way to do this is pass the interface
	 * as a parameter, but we have not learnt `static`
	 * member functions and functions with `template`.
	 *
	 * So forgive me for this ugly part :).
	 */

	{
		auto temp = arr;
		timer.reset();
		timer.start();
		sorter.bubble_sort(temp);
		timer.stop();

		assert(temp == answer);
		time_bubble_sort = timer.time();
	}

	{
		auto temp = arr;
		timer.reset();
		timer.start();
		sorter.quick_sort(temp);
		timer.stop();

		assert(temp == answer);
		time_quick_sort = timer.time();
	}

	{
		auto temp = arr;
		timer.reset();
		timer.start();
		sorter.merge_sort(temp);
		timer.stop();

		assert(temp == answer);
		time_merge_sort = timer.time();
	}

	double baseline = std::max({time_bubble_sort,
								time_quick_sort,
								time_merge_sort
							   });
	// The baseline would be bubble sort for big `len`.
	std::cout << "Baseline: " << baseline << " seconds" << std::endl;
	std::cout << "Bubble Sort | Time Usage (s): " << time_bubble_sort <<
			  ", Improvement: " << calc_improvement(time_bubble_sort, baseline) <<
			  std::endl;
	std::cout << "Quick Sort  | Time Usage (s): " << time_quick_sort <<
			  ", Improvement: " << calc_improvement(time_quick_sort, baseline) <<
			  std::endl;
	std::cout << "Merge Sort  | Time Usage (s): " << time_merge_sort <<
			  ", Improvement: " << calc_improvement(time_merge_sort, baseline) <<
			  std::endl;
	return 0;
}
