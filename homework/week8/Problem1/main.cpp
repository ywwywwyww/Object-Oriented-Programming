#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "my_trie.h"
#include "generator.h"
#include "suffix_trie.h"

using namespace std;

int main() {
  MyTrie *my_trie = new MyTrie();


  //add code here to randomly generate 15 character strings
  // and then insert the character strings into trie
  Generator::GetInstance().GenerateString(my_trie, 15, 8);
  //search other prefixes instead of "a" if needed
  my_trie->searchSubString("a");
  //print all the matches to standard output by cout/printf
  //You may determine the output format
  my_trie->printMatches();

  my_trie->searchSubString("b");
  //print all the matches to standard output by cout/printf
  //You may determine the output format
  my_trie->printMatches();

  my_trie->searchSubString("c");
  //print all the matches to standard output by cout/printf
  //You may determine the output format
  my_trie->printMatches();

  my_trie->searchSubString("ab");
  //print all the matches to standard output by cout/printf
  //You may determine the output format
  my_trie->printMatches();

  //destruct the trie
  delete my_trie;

  SuffixTrie *suffix_trie = new SuffixTrie{};


  //add code here to randomly generate 15 character strings
  // and then insert the character strings into trie
  Generator::GetInstance().GenerateString(suffix_trie, 15, 8);
  //search other prefixes instead of "a" if needed
  suffix_trie->searchSubString("a");
  //print all the matches to standard output by cout/printf
  //You may determine the output format
  suffix_trie->printMatches();

  suffix_trie->searchSubString("b");
  //print all the matches to standard output by cout/printf
  //You may determine the output format
  suffix_trie->printMatches();

  suffix_trie->searchSubString("c");
  //print all the matches to standard output by cout/printf
  //You may determine the output format
  suffix_trie->printMatches();

  suffix_trie->searchSubString("ab");
  //print all the matches to standard output by cout/printf
  //You may determine the output format
  suffix_trie->printMatches();

  //destruct the trie
  delete suffix_trie;

  return 0;
}
