cmake_minimum_required(VERSION 3.15)
project(Problem1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Problem1 main.cpp BaseTrie.h BaseTrie.cpp my_trie.cpp my_trie.h generator.cpp generator.h suffix_trie.cpp suffix_trie.h)