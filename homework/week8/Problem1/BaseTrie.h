#ifndef BASETRIE_H_INCLUDED
#define BASETRIE_H_INCLUDED

#include <vector>
#include <string>
#include <cstdlib>

struct TrieNode {
  const static int CHILDNUM = 26;
  TrieNode() : value_(-1) {
    for (int i = 0; i < CHILDNUM; ++i) {
      next_[i] = NULL;
    }
  }
  int value_;
  TrieNode *next_[CHILDNUM];
};

class BaseTrie {
 private:
  TrieNode *pRoot_;
  void traverse(TrieNode *p, std::string str);
  /**
   * Releases the trie
   * Used in destructor
   */
  void Release(TrieNode *&current_node);
 public:
  BaseTrie() : pRoot_(NULL) {}
  void insert(const char *s, int value);
  int search(const char *s);
  void searchSubString(const char *s);
  virtual void getString(std::string &str, int &value) = 0;
  /**
   * The virtual destructor
   */
  virtual ~BaseTrie();
};

#endif // BASETRIE_H_INCLUDED
