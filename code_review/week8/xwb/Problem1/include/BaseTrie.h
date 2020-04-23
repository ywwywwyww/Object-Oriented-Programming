/**
 * @file BaseTrie.h
 * @author Kirin (1370302499@qq.com)
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright Copyright (c) 2020 Kirin
 *
 * @brief based on provided version
 *
 **/

#ifndef BASETRIE_H_INCLUDED
#define BASETRIE_H_INCLUDED

#include <cstdlib>
#include <string>
#include <vector>

struct TrieNode {
  const static int CHILDNUM = 26;
  TrieNode() : value_(-1) {
    for (int i = 0; i < CHILDNUM; ++i) {
      next_[i] = NULL;
    }
  }
  ~TrieNode() {
    for (auto son : next_) delete son;
  }
  int value_;
  TrieNode* next_[CHILDNUM];
};

class BaseTrie {
 public:
  BaseTrie() : pRoot_(NULL) {}
  virtual ~BaseTrie();
  void insert(const char* s, int value);
  int search(const char* s);
  void searchSubString(const char* s);

 protected:
  virtual void getString(std::string str, int value) = 0;

 private:
  void traverse(TrieNode* p, std::string str);
  TrieNode* pRoot_;
};

#endif  // BASETRIE_H_INCLUDED
