/**
 * @file generator.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "generator.h"

std::string Generator::GenerateString() {
  std::string string {};
  const int kLength = 16;
  for (int i = 1; i <= kLength; i++) {
    if (int ch = rand() % 36; ch < 10) {
      string += ch + '0';
    } else {
      string += ch - 10 + 'a';
    }
  }
  return string;
}

std::string Generator::GenerateId() {
  std::string string {};
  do {
    string = this->GenerateString();
  } while(this->ids_.count(string) != 0);
  this->ids_.insert(string);
  return string;
}