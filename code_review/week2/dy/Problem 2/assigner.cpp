/**
 * @file				assigner.cpp
 * @author				Yan DAI
 * @date				Feb 26, 2020
 *
 * Implements all member functions of class `ReviewerAssigner`.
 */

#include "assigner.h"

void ReviewerAssigner::load(std::string filename)
{
	students.clear();
	emails.clear();
	std::fstream file_in(filename, std::fstream::in);

	std::string student_id, email;
	file_in >> student_id >> email; // Ignore the first line.
	while (file_in >> student_id >> email)
	{
		students.push_back(student_id);
		emails.push_back(email);
	}
}

void ReviewerAssigner::choose()
{
	int n = students.size();
	reviewers.resize(n);
	for (int i = 0; i < n; i++)
	{
		int a = 0, b = 0, c = 0;
		do
			a = generate_random(0, n - 1);
		while (a == i); // Reviewer cannot be student i himself
		do
			b = generate_random(0, n - 1);
		while (b == i || b == a); // Reviewers cannot duplicate
		do
			c = generate_random(0, n - 1);
		while (c == i || c == b || c == a);
		reviewers[i] = std::make_tuple(a, b, c);
	}
}

void ReviewerAssigner::output(std::string filename)
{
	std::fstream file_out(filename, std::fstream::out);
	file_out << "Student ID\t\tReviewer 1\t\tReviewer 2\t\t" <<
			 "Reviewer 3\t\t\tEmail\t\t\tReviewer 1 Email\t\t\t" <<
			 "Reviewer 2 Email\t\t\tReviewer 3 Email" << std::endl;
	for (int i = 0; i < students.size(); i++)
		file_out << students[i] << "\t\t" <<
				 students[std::get<0>(reviewers[i])] << "\t\t" <<
				 students[std::get<1>(reviewers[i])] << "\t\t" <<
				 students[std::get<2>(reviewers[i])] << "\t\t" <<
				 emails[i] << "\t\t\t" <<
				 emails[std::get<0>(reviewers[i])] << "\t\t\t" <<
				 emails[std::get<1>(reviewers[i])] << "\t\t\t" <<
				 emails[std::get<2>(reviewers[i])] << std::endl;
}
