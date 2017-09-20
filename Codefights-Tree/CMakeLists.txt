cmake_minimum_required(VERSION 3.7)
project(Codefights_Tree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Trie.cpp)
add_executable(Codefights_Tree ${SOURCE_FILES})