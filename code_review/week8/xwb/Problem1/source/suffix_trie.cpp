/**
 * @file suffix_trie.cpp
 * @author Kirin (1370302499@qq.com)
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright Copyright (c) 2020 Kirin
 *
 * @brief details of class @c SuffixTrie defined in suffix_trie.hpp
 *
 **/

#include "suffix_trie.hpp"

#include <algorithm>  //for std::reverse
#include <ostream>    //for std::ostream
#include <string>     //for std::string
#include <utility>    //for std::move

void SuffixTrie::insert(std::string str, int cnt) {
  this->adaptStr(str);
  this->Base::insert(str.c_str(), cnt);
}

int SuffixTrie::search(std::string str) {
  this->adaptStr(str);
  return this->Base::search(str.c_str());
}
void SuffixTrie::searchSubString(std::string suffix) {
  this->adaptStr(suffix);
  this->Base::searchSubString(suffix.c_str());
}

void SuffixTrie::printMatches(std::ostream& os) {  // os = std::cout
  this->Base::printMatches(os);
}
void SuffixTrie::printAll(std::ostream& os) {  // os = std::cout
  this->Base::printAll(os);
}

void SuffixTrie::getString(std::string str, int cnt) {
  this->adaptStr(str);
  this->Base::getString(std::move(str), cnt);
}

void SuffixTrie::adaptStr(std::string& str) const {
  std::reverse(str.begin(), str.end());
}
