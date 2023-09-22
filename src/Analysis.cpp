#include"Analysis.hpp"

vector<string> getInputWords() {
    ifstream inputFile("./dataset/input.data");

    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        exit(1);
    }

    vector<string> words;

    string word;

    while (inputFile >> word) words.push_back(word);

    inputFile.close();

    return words;
}

void Analysis(){

  setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  //local variables
  int counter = 1,counter_words = 0;//this variable is use for show in what text is analysing.
  wchar_t *txt = getText(loc,counter), *ch = txt;//for variable that walking the text 
  std::ofstream output = createOutput(); 
  wstring word;//for the word that will read of the input text
  StopWords stop_words(loc);//for stop words
  Hashh mp;//for hash
  srand(42); 
  Vector Heapp;
  vector<string> inputWords = getInputWords();  
  int contador_aux = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

  //main loop
  while (*ch && (counter_words < inputWords.size())) {
    switch(*ch) 
    {
      //in case the ch is in the end sentence or a speak or a question.
      case L'.': case L'!': case L'?':
        if(!word.empty()) 
        {
          std::wstring wstr = converter.from_bytes(inputWords[counter_words]);
          if(word == wstr)
          {
            contador_aux++;
          }
          if(stop_words.isStopWord(word)) 
            {
              word.clear();
            } 
          else 
            {
              mp.addWord(word);
            }
        }
        word.clear();
        break;

      //in case the ch is in the skip of line.
      case L'\n':
        if(!word.empty()) {
          std::wstring wstr = converter.from_bytes(inputWords[counter_words]);
          if(word == wstr)
          {
            contador_aux++;
          }
            if(stop_words.isStopWord(word)) {
              word.clear();
            } else {
              mp.addWord(word);
            }
          }
          word.clear();
        break;

      //in case the ch is between space, comma, feature, quotation marks, bar, two points
      case L' ': case L',': case L':':
      case L';': case L'(': case L')':
      case L'"': case L'-': case L'/':
        if(!word.empty()) {
          std::wstring wstr = converter.from_bytes(inputWords[counter_words]);
          if(word == wstr)
          {
            contador_aux++;
          }
          if(stop_words.isStopWord(word)) {
              word.clear();
            } else {
              mp.addWord(word);
            }

          word.clear();
        }
        break;

      //if there is no case, the letter will be concatenated with the word that had already been formed with the preceding letters.
      default:
        word += tolower(*ch);
      break;
    }
    ++ch;
    if(!(*ch))
    {
      Tree_1 *tre = createTree();
      Tree_AVL *avl = createTree_AVL();

     if(contador_aux > 0){      
      std::wstring wstr = converter.from_bytes(inputWords[counter_words]);
      FillingHeap(Heapp,mp,wstr);

      //in here filling all trees
      FillingBasicTree(Heapp,&tre);

      FillingAvl(Heapp,&avl);

      //in here add the print of the heap.
      PrintEnd(output,Heapp,counter,inputWords[counter_words],contador_aux);
      
     
      central(&tre,output);

      output << "\nAVL TREE:\n\n";

      central_AVL(avl,output);

      output << "\nHUFFMAN:\n\n";
      FillingHuffman(Heapp,output);
      
      output << "======================================================================================================================================\n";

      }
       counter++;
      contador_aux = 0;

      if(counter == 7)
      {
        counter_words ++;
        counter = 1;
      }
      if(counter == 7 && counter_words == inputWords.size())
      {
        counter = 10;
      }

      if(counter < 7){

        mp.mp.clear();//clear the hash for other input text
        Heapp.vet.clear();
        ch = getText(loc,counter);//puting other text and inserting in the variable ch.
        free(avl);
        free(tre);

      }else{
        output.close();
        delete[] txt;
        exit(-1);
      }
    }
  }

  
  return ;
}

//end code
