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
  /**
   * Generates a random distinct id
   * @return The id
   */
  std::string GenerateId();
 private:
  Generator() : ids_{} {
    srand(time(NULL));
  };
  Generator(Generator &) = default;
  Generator(Generator &&) = default;
  /**
   * Generates a random string
   * @return The string
   */
  std::string GenerateString();
  std::set<std::string> ids_; // The generated ids
};

#endif //PROBLEM1__GENERATOR_H_
