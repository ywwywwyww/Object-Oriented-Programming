/**
 * @file reviewer_assigner.h
 * @author Wuwei YUAN
 * @date 3/4/2020
 */

#ifndef PROBLEM2__REVIEWER_ASSIGNER_H_
#define PROBLEM2__REVIEWER_ASSIGNER_H_

#include <string>
#include <vector>
#include <utility>

/**
 * Assigns reviewers
 * Example:
 *    ReviewerAssigner reviewer_assigner{};
 *    reviewer_assigner.load("ContactEmail.txt");
 *    reviewer_assigner.choose(3);
 *    reviewer_assigner.output("reviewer.csv");
 */
class ReviewerAssigner {
 public:
  /**
   * Loads students list from given file
   * @param list_filename The filename of students list
   */
  void load(const std::string &list_filename);

  /**
   * Choose reviewer(s) for each student
   * @param num_reviewer_for_each_student Num of reviewer(s) to be assigned for each student
   */
  void choose(const int &num_reviewer_for_each_student);

  /**
   * Outputs assignment result to given file in .csv format
   * @param assignment_result_filename The filename of result file, it is recommended to be a .csv file
   */
  void output(const std::string &assignment_result_filename);

 private:
  std::vector<std::string> students_;
  std::vector<std::vector<int>> assignment_result_;
  int num_reviewers_for_each_student_;
};

#endif //PROBLEM2__REVIEWER_ASSIGNER_H_
