#include"Words.hpp"

Words::Words(const std::locale &loc) : counter_words(0) 
{

  wifstream txt("./dataset/input.data");

  txt.imbue(loc);

  wstring tmp;
  //short int counter_words = 0;

    while(getline(txt, tmp))
    {

      this->words.insert(tmp);
      this->counter_words++;

    }

  txt.close();
}

void Words::Print(){

  cout << this->counter_words<<endl;

}
