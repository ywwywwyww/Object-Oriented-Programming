/**
 * @file random.cpp
 * @author Kirin (1370302499@qq.com)
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright Copyright (c) 2020 Kirin
 *
 * @brief definition of random functions declared in random.hpp
 *
 **/

#include "random.hpp"

#include <cstddef>  //for std::size_t
#include <random>  //for std::random_device, std::mt19937_64, std::uniform_int_distribution
#include <string>  //for std::string

namespace {
// all functions will use the same random engine
std::mt19937_64& rand_eng() {
  // use std::random_device as seed
  static std::mt19937_64 engine(std::random_device{}());
  return engine;
}
}  // namespace

int rand_int(int l, int r) {
  return std::uniform_int_distribution<int>(l, r)(rand_eng());
}
std::string rand_lowercase_str(std::size_t len) {
  std::uniform_int_distribution<char> rand('a', 'z');
  std::string ret;
  while (len-- > 0) ret += rand(rand_eng());
  return ret;
}
