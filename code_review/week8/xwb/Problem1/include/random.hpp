/**
 * @file random.hpp
 * @author Kirin (1370302499@qq.com)
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright Copyright (c) 2020 Kirin
 *
 * @brief declaration of random functions
 *
 **/

#include <cstddef>  //for std::size_t
#include <string>   //for std::string

// return a random integer in [l,r]
int rand_int(int l, int r);
// return a string of `len` random lowercases in length
std::string rand_lowercase_str(std::size_t len);
