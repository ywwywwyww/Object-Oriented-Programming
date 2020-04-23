/**
 * @file suffixTrie.h
 * @author Wuwei YUAN
 * @date 4/10/20
 */

#ifndef PROBLEM1__SUFFIX_TRIE_H_
#define PROBLEM1__SUFFIX_TRIE_H_

#include "my_trie.h"
#include "BaseTrie.h"

class SuffixTrie : private BaseTrie {
 public:
  SuffixTrie() : trie_{new MyTrie{}} {}
  /**
   * The virtual destructor
   */
  virtual ~SuffixTrie() {
    delete this->trie_;
  }
  /**
   * inserts a string into the trie
   * @param s The string
   * @param value The value of the string
   */
  virtual void insert(const char *s, int value);
  /**
   * Searches the strings with give suffix
   * @param s The given suffix
   */
  virtual void searchSubString(const char *s);
  /**
   * Prints the matched strings in preceding searching stage
   */
  virtual void printMatches();
 private:
  virtual void getString(std::string &str, int &value);
  MyTrie *trie_; // The trie
};

#endif //PROBLEM1__SUFFIX_TRIE_H_
