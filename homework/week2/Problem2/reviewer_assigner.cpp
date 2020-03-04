//
// Created by yww on 3/3/20.
//

#include "reviewer_assigner.h"

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iostream>

void ReviewerAssigner::load(const std::string &list_filename) {
  std::ifstream fin{list_filename};
  if (!fin) {
    std::cerr <<"ERROR file does no exit: " << list_filename << "\n";
    return;
  }
  const int kMaxLength = 100;
  char line[kMaxLength];
  fin.getline(line, kMaxLength);
  while (fin) {
    fin.getline(line, kMaxLength);
    int length = std::strlen(line);
    if (length == 0) {
      break;
    }
    line[length - 1] = '\0';
    std::string student{line};
    student[student.find('\t')] = ' ';
    students_.emplace_back(student);
  }
}

void ReviewerAssigner::choose(const int &num_reviewer_for_each_student) {
  num_reviewers_for_each_student_ = num_reviewer_for_each_student;
  srand(time(NULL));
  int num_students = students_.size();
  for (int i = 0; i < num_students; i++) {
    assignment_result_.emplace_back();
    std::set<int> assigned;
    assigned.insert(i);
    for (int j = 0; j < num_reviewer_for_each_student; j++) {
      int reviewer;
      do {
        reviewer = rand() % num_students;
      } while (assigned.count(reviewer) != 0);
      assignment_result_[i].push_back(reviewer);
      assigned.insert(reviewer);
    }
  }
}

void ReviewerAssigner::output(const std::string &assignment_result_filename) {
  std::ofstream fout{assignment_result_filename};
  fout << "student";
  for (int i = 0; i < num_reviewers_for_each_student_; i++) {
    fout << ",\"reviewer " << i << "\"";
  }
  fout << "\n";
  int num_students = students_.size();
  for (int i = 0; i < num_students; i++) {
    fout << "\"" << students_[i] << "\"";
    for (int j = 0; j < num_reviewers_for_each_student_; j++) {
      fout << ",\"" << students_[assignment_result_[i][j]] << "\"";
    }
    fout << "\n";
  }
}