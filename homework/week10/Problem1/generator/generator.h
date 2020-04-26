/**
 * @file generator.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1__GENERATOR_H_
#define PROBLEM1__GENERATOR_H_

#include <set>
#include <string>
#include <ctime>
#include <cstdlib>

class Generator {
 public:
  static Generator& GetInstance() {
    static Generator instance;
    return instance;
  }
  std::string GenerateId();
 private:
  Generator() : ids{} {
    srand(time(NULL));
  };
  Generator(Generator &) = default;
  Generator(Generator &&) = default;
  std::string GenerateString();
  std::set<std::string> ids;
};

#endif //PROBLEM1__GENERATOR_H_
