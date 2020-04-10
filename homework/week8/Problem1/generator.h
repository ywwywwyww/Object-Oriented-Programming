/**
 * @file generator.h
 * @author Wuwei YUAN
 * @date 4/10/20
 */

#ifndef PROBLEM1__GENERATOR_H_
#define PROBLEM1__GENERATOR_H_

#include <iostream>
#include "BaseTrie.h"

class Generator {
 public:
  /**
   * Generate strings and inserts them into a trie
   * @tparam T Type of the trie
   * @param trie The give trie
   * @param num The number of strings
   * @param length The length of each strings
   */
  template <typename T> void GenerateString(T *trie, const int &num, const int &length);
  /**
   * Gets the only instance of generator
   * @return The instance
   */
  static Generator& GetInstance() {
    static Generator instance;
    return instance;
  }

 private:
  ~Generator() = default;
  Generator(const Generator&) = default;
  Generator(Generator&&) = default;
  Generator& operator =(const Generator&) = default;
  /**
   * Constructor
   * Initializes the pseudo-random number generator
   */
  Generator() {
    srand(time(nullptr));
  }
};

// Put the definition here to avoid linking error
template <typename T>
void Generator::GenerateString(T *trie, const int &num, const int &length) {
  char string[length + 1];
  string[length] = '\0';
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < length; j++) {
      string[j] = 'a' + rand() % 26;
    }
    trie->insert(string, rand());
//    std::cerr << string << std::endl;
  }
}

#endif //PROBLEM1__GENERATOR_H_
