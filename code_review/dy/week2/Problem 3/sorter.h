/**
 * @file				sorter.h
 * @author				Yan DAI
 * @date				Feb 26, 2020
 *
 * Define the class `Sorter`.
 */

#ifndef __SORTER_H__
#define __SORTER_H__

#include <vector>

class Sorter
{
	void quick_sort_helper(std::vector<int> &arr,
						   int left, int right);
	void merge_sort_helper(std::vector<int> &arr,
						   int left, int right);

public:
	Sorter() = default;
	~Sorter() = default;

	/**
	 * All the following interfaces will sort the parameter
	 * (an `std::vector<int> &` type) from small to large,
	 * and then save the result back.
	 */
	void bubble_sort(std::vector<int> &arr);
	void quick_sort(std::vector<int> &arr);
	void merge_sort(std::vector<int> &arr);
};

#include <cstdlib> // For generating random numbers.

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
// If in Windows platform, RAND_MAX will be 65536 instead of INT_MAX.
#define rand() ((rand() << 16) | rand())
#endif

/**
 * Generate a random number in range [left, right].
 *
 * @param left  The left boundary of the range.
 * @param right The right boundary of the range.
 */
inline int generate_random(int left, int right)
{
	return rand() % (right - left + 1) + left;
}

#endif
