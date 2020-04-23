/**
 * @file suffix_trie.hpp
 * @author Kirin (1370302499@qq.com)
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright Copyright (c) 2020 Kirin
 *
 * @brief definition of class @c SuffixTrie
 *
 **/

#include <iostream>  //for std::cout
#include <ostream>   //for std::ostream
#include <string>    //for std::string

#include "MyTrie.h"

class SuffixTrie : private MyTrie {
 public:
  // insert string `str` into this trie for `cnt` times
  void insert(std::string str, int cnt);
  // search `str` in this trie
  int search(std::string str);
  // search strings end with `suffix`
  void searchSubString(std::string suffix);
  // print strings found by function getString
  void printMatches(std::ostream& os = std::cout);
  // print all the strings in this trie
  void printAll(std::ostream& os = std::cout);

 protected:
  virtual void getString(std::string str, int cnt) override;

 private:
  using Base = MyTrie;

  void adaptStr(std::string& str) const;
};
