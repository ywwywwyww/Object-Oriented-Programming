//
// Created by yww on 3/3/20.
//

#ifndef PROBLEM2__REVIEWER_ASSIGNER_H_
#define PROBLEM2__REVIEWER_ASSIGNER_H_

#include <string>
#include <vector>
#include <utility>

/**
 * a reviewer assigner
 */
class ReviewerAssigner {
 public:
  /**
   * load students list from given file
   * @param list_filename students list filename
   */
  void load(const std::string &list_filename);

  /**
   * choose reviewer(s) for each student
   * @param num_reviewer_for_each_student num of reviewer(s) for each student
   */
  void choose(const int &num_reviewer_for_each_student);

  /**
   * output assignment result to given file
   * @param assignment_result_filename result filename
   */
  void output(const std::string &assignment_result_filename);

 private:
  std::vector<std::string> students_;
  std::vector<std::vector<int>> assignment_result_;
  int num_reviewers_for_each_student_;
};

#endif //PROBLEM2__REVIEWER_ASSIGNER_H_
