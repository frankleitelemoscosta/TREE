#ifndef __HASH_HPP
#define __HASH_HPP

#include<unordered_map>
#include <string>

struct Data {
  unsigned short appearences;
  Data();
};

struct Hashh {
  std::unordered_map<std::wstring, Data> mp;
  void addWord(const std::wstring &word);
};

#endif
