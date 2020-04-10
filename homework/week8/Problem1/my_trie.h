/**
 * @file MyTrie.h
 * @author Wuwei YUAN
 * @date 4/10/20
 */

#ifndef PROBLEM1__MY_TRIE_H_
#define PROBLEM1__MY_TRIE_H_

#include "BaseTrie.h"

class MyTrie : public BaseTrie {
 public:
  MyTrie() : BaseTrie{} {};
  virtual ~MyTrie() = default;
  /**
   * Prints the matched strings in preceding searching stage
   * @param reverse Whether to reverse the result strings
   */
  virtual void printMatches(bool reverse = false);
 protected:
  /**
   * Stores the matched strings in a buffer
   * @param str The matched string
   * @param value The value of the string
   */
  virtual void getString(std::string &str, int &value) override;
 private:
  std::vector<std::pair<std::string, int>> search_results_; // Buffer of matched strings
};

#endif //PROBLEM1__MY_TRIE_H_
