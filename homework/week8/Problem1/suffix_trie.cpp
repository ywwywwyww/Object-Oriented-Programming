/**
 * @file suffixTrie.cpp
 * @author Wuwei YUAN
 * @date 4/10/20
 */

#include <cstring>
#include "suffix_trie.h"

void SuffixTrie::insert(const char *s, int value) {
  int length = strlen(s);
  char *string_temp = new char[length + 1];
  string_temp[length] = '\0';
  for(int i = 0; i < length; i++) {
    string_temp[i] = s[length - i - 1];
  }
  this->trie_->insert(string_temp, value);
  delete[] string_temp;
}

void SuffixTrie::searchSubString(const char *s) {
  int length = strlen(s);
  char *string_temp = new char[length + 1];
  string_temp[length] = '\0';
  for(int i = 0; i < length; i++) {
    string_temp[i] = s[length - i - 1];
  }
  this->trie_->searchSubString(string_temp);
  delete[] string_temp;
}

void SuffixTrie::printMatches() {
  this->trie_->printMatches(true);
}

void SuffixTrie::getString(std::string &str, int &value) {}