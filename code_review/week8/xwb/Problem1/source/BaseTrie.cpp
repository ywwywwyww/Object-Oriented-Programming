/**
 * @file BaseTrie.cpp
 * @author Kirin (1370302499@qq.com)
 * @version 0.1
 * @date 2020-04-11
 *
 * @copyright Copyright (c) 2020 Kirin
 *
 * @brief based on provided version
 *
 **/

#include "BaseTrie.h"

#include <cassert>
#include <stack>
using namespace std;

BaseTrie::~BaseTrie() { delete pRoot_; }

void BaseTrie::insert(const char *s, int value) {
  TrieNode *p = NULL;
  if (!(p = pRoot_)) p = pRoot_ = new TrieNode();
  int i = 0, k = 0;
  while (s[i]) {
    k = s[i++] - 'a';
    if (!p->next_[k]) p->next_[k] = new TrieNode();
    p = p->next_[k];
  }
  p->value_ = value;
}

int BaseTrie::search(const char *s) {
  TrieNode *p = NULL;
  if (!(p = pRoot_)) return -1;
  int i = 0, k = 0;
  while (s[i]) {
    k = s[i++] - 'a';
    if (p->next_[k] == NULL) return -1;
    p = p->next_[k];
  }
  return p->value_;
}

void BaseTrie::searchSubString(const char *s) {
  TrieNode *p = NULL;
  if (!(p = pRoot_)) return;
  int i = 0, k = 0;
  while (s[i]) {
    k = s[i++] - 'a';
    if (p->next_[k] == NULL) return;
    p = p->next_[k];
  }
  // enumerate all the children
  string str = s;
  traverse(p, str);
}

void BaseTrie::traverse(TrieNode *p, string str) {
  if (p->value_ >= 0) {
    getString(str, p->value_);
  }
  for (int i = 0; i < TrieNode::CHILDNUM; ++i) {
    if (p->next_[i]) {
      char c = 'a' + i;
      traverse(p->next_[i], (str + c));
    }
  }
}
