/**
 * @file main.cpp
 * @author Wuwei YUAN
 * @date 3/4/2020
 */

#include "reviewer_assigner.h"
#include <cstdlib>
#include <ctime>

int main() {
  srand(time(NULL));
  ReviewerAssigner reviewer_assigner{};
  reviewer_assigner.load("ContactEmail.txt");
  reviewer_assigner.choose(3);
  reviewer_assigner.output("reviewer.txt");
  return 0;
}
