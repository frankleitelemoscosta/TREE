#include"Analysis.hpp"

void Analysis(){

  setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  //local variables
  int counter = 1;//this variable is use for show in what text is analysing.
  wchar_t *txt = getText(loc,counter), *ch = txt;//for variable that walking the text 
  wofstream output = createOutput(loc);
  wstring word;//for the word that will read of the input text
  StopWords stop_words(loc);//for stop words
  Hashh mp;//for hash
  srand(42); 
  Vector Heapp;

  //init the output file.
  printStart(output);
  
  //main loop
  while (*ch) {

    switch(*ch) 
    {
      //in case the ch is in the end sentence or a speak or a question.
      case L'.': case L'!': case L'?':
        if(!word.empty()) 
        {
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
      printf("File number: %d\n",counter);
      counter++;
      Tree_1 *tre = createTree();


      FillingHeap(Heapp,mp);
 
      //in here filling all trees
      FillingBasicTree(Heapp,&tre);

      printf("METODO CENTRAL: { ");                                                                
          central(tre);

          printf("}\n\n"); 

      //in here add the print of the heap.
      printEnd(Heapp,output);

      if(counter < 7){

        mp.mp.clear();//clear the hash for other input text
        Heapp.vet.clear();
        ch = getText(loc,counter);//puting other text and inserting in the variable ch.
      
      }else{
        break;
      }
    }
  }

  
  output.close();
  delete[] txt;
  return ;
}

//end code
