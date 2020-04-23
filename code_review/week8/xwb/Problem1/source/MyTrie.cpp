/**
 * @file MyTrie.cpp
 * @author Kirin (1370302499@qq.com)
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright Copyright (c) 2020 Kirin
 *
 * @brief details of class @c MyTrie defined in MyTrie.h
 *
 **/

#include "MyTrie.h"

#include <ostream>  //for std::ostream, std::endl
#include <string>   //for std::string
#include <utility>  //for std::move

void MyTrie::printMatches(std::ostream& os) {  // os = std::cout
  if (m_str_found.empty()) {
    os << "no matched strings!" << std::endl;
    return;
  }
  for (const auto& [str, cnt] : m_str_found)
    os << str << ' ' << cnt << std::endl;
  m_str_found.clear();  // clear the buffer
}
void MyTrie::printAll(std::ostream& os) {  // os = std::cout
  this->searchSubString("");
  for (const auto& [str, cnt] : m_str_found)
    os << str << ' ' << cnt << std::endl;
  m_str_found.clear();
}

void MyTrie::getString(std::string str, int cnt) {
  m_str_found.emplace_back(std::move(str), cnt);
}
