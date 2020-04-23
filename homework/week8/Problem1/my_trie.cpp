/**
 * @file MyTrie.cpp
 * @author Wuwei YUAN
 * @date 4/10/20
 */

#include <iostream>
#include <algorithm>
#include "my_trie.h"

void MyTrie::getString(std::string &str, int &value) {
  this->search_results_.emplace_back(str, value);
}

void MyTrie::printMatches(bool reverse) {
  for (auto& [string, value] : this->search_results_) {
    // Reverse the result string for the SuffixTrie
    if (reverse) {
      std::reverse(string.begin(),string.end());
    }
    std::cout << string << " " << value << '\n';
  }
  std::cout << "Total #strings matched: " << this->search_results_.size() << '\n' << std::endl;
  this->search_results_.clear();
}