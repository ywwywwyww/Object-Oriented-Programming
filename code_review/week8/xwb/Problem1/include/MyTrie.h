/**
 * @file MyTrie.h
 * @author Kirin (1370302499@qq.com)
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright Copyright (c) 2020 Kirin
 *
 * @brief definition of class @c MyTrie
 *
 **/

#pragma once

#ifndef KIRIN_MYTRIE_H_INCLUDED
#define KIRIN_MYTRIE_H_INCLUDED

#include <iostream>  //for std::cout
#include <ostream>   //for std::ostream
#include <string>    //for std::string
#include <utility>   //for std::pair
#include <vector>    //for std::vector

#include "BaseTrie.h"

class MyTrie : public BaseTrie {
 public:
  // print strings found by function getString
  void printMatches(std::ostream& os = std::cout);
  // print all the strings in this trie
  void printAll(std::ostream& os = std::cout);

 protected:
  virtual void getString(std::string str, int cnt) override;

  // a buffer that stores strings found by function getString
  std::vector<std::pair<std::string, int>> m_str_found;
};

#endif  // KIRIN_MYTRIE_H_INCLUDED
