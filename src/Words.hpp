#ifndef WORDS_HPP
#define WORDS_HPP

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<unordered_set>

using namespace std;

typedef struct Words Words;

struct Words{
  std::unordered_set<wstring> words;
  int counter_words;
  Words(const std::locale &loc);
  void Print();
};




#endif
