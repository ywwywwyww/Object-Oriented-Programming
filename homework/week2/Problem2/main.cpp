#include "reviewer_assigner.h"

int main() {
  ReviewerAssigner reviewer_assigner{};
  reviewer_assigner.load("ContactEmail.txt");
  reviewer_assigner.choose(3);
  reviewer_assigner.output("reviewer.txt");
  return 0;
}
