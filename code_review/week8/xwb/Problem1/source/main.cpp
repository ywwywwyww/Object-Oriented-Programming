/**
 * @file main.cpp
 * @author Kirin (1370302499@qq.com)
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright Copyright (c) 2020 Kirin
 *
 * @brief based on provided version
 *
 **/

#include <iostream>     //for std::cout, std::endl
#include <string_view>  //for std::string_view

#include "MyTrie.h"
#include "random.hpp"
#include "suffix_trie.hpp"

// functionality Testing
template <typename Trie>
void test(Trie *trie, std::string_view pre_or_suf) {
  // add code here to randomly generate 15 character strings
  // and then insert the character strings into trie
  constexpr int STRING_CNT = 15, STRING_LEN = 8;
  for (int i = 0; i < STRING_CNT; ++i)
    trie->insert(rand_lowercase_str(STRING_LEN).c_str(), rand_int(1, 10));
  std::cout << "trie contains:" << std::endl;
  trie->printAll();

  // search prefixes/suffixes `str`
  // print all the matches to standard output
  for (char str[] = "a"; str[0] <= 'z'; ++str[0]) {
    trie->searchSubString(str);
    std::cout << "strings with " << pre_or_suf << " \"" << str
              << "\" :" << std::endl;
    trie->printMatches();
  }
}

int main() {
  // test `MyTrie`
  std::cout << "---now testing MyTrie---" << std::endl;
  MyTrie *my_trie = new MyTrie();
  test(my_trie, "prefix");
  delete my_trie;

  // test `SuffixTrie`
  std::cout << "---now testing SuffixTrie---" << std::endl;
  SuffixTrie *suffix_trie = new SuffixTrie();
  test(suffix_trie, "suffix");
  delete suffix_trie;
}
