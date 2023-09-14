#include "StopWords.hpp"
#include <fstream>

using namespace std;

StopWords::StopWords(const std::locale &loc)
{
  wifstream txt("./dataset/stopwords.txt");

  if(!txt.is_open()) exit(1);

  txt.imbue(loc);

  wstring tmp;

    while(getline(txt, tmp))
    {

        this->mp.insert(tmp);
    
    }

  txt.close();
}

bool StopWords::isStopWord(const std::wstring &word)
{
  return mp.count(word) != 0;
}