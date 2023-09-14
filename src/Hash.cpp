#include"Hash.hpp"

Data::Data() : appearences(0) {}

void Hashh::addWord(const std::wstring &word)
{
  ++mp[word].appearences;
}
