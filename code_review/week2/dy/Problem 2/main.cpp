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

#include "assigner.h"

#include <cstdlib> // For `rand()` function.
#include <ctime> // For seeding `rand()` function.

int main(int argc, char **argv)
{
	srand(time(NULL));

	ReviewerAssigner reviewer_assigner;
	reviewer_assigner.load("ContactEmail.txt");
	reviewer_assigner.choose();
	reviewer_assigner.output("reviewer.txt");
	return 0;
}
