/**
 * @file				assigner.h
 * @author				Yan DAI
 * @date				Feb 26, 2020
 *
 * Define the class `ReviewerAssigner`.
 */

#ifndef __ASSIGNER_H__
#define __ASSIGNER_H__

#include <fstream> // For reading/writing files.
#include <vector>
#include <string> // For filename.
#include <tuple>

class ReviewerAssigner
{
	// Storing all students and emails in the same order.
	std::vector<std::string> students, emails;

	// The assigning result.
	std::vector<std::tuple<int, int, int> > reviewers;

public:
	ReviewerAssigner() = default;
	~ReviewerAssigner() = default;

	void load(std::string filename);
	void choose();
	void output(std::string filename);
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
