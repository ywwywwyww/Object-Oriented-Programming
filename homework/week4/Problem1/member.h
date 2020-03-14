/**
 * @file member.h
 * @author Wuwei YUAN
 * @date 3/14/20
 */

#ifndef PROBLEM1__MEMBER_H_
#define PROBLEM1__MEMBER_H_

#include <string>
#include <iostream>

/**
 * A class to store a member
 * example:
 *     Member a{'aaa', 1};
 *     a.printInfo();
 */
class Member {
 public:
  /**
   * Initializes the member with his(her) name and age
   * @param name Name of the member
   * @param age Age of the member
   */
  Member(const std::string &name, const int &age)
      : name_{name}, age_{age} {}

  /**
   * Initializes the member with "???" as his(her) name and 0 as his age
   */
  Member()
      : Member{"???", 0} {}

  /**
   * Outputs name and age of the member
   */
  void printInfo() const {
    std::cout << "name: " << name_ << " age: " << age_ << std::endl;
  }

 private:
  const std::string name_; // Name of the member
  const int age_; // Age of the member
};

#endif //PROBLEM1__MEMBER_H_
