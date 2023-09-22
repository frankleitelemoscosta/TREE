#include"Utils.hpp"

//this function open and return a variable with the text
wchar_t *getText(const std::locale &loc,int counter)
{

  string number;
  string name = "./dataset/txt0";
  
  number = to_string(counter);

  name = name + number;
  name = name + ".txt";

  wifstream txt(name, ios::binary);

  if(!txt.is_open()) {
    wcout << L"Não foi possível abrir o arquivo" << endl;
    exit(1);
  }

  // Set the locale to handle UTF-8 encoding
  txt.imbue(loc);

  // Determine the size of the file in bytes
  txt.seekg(0, ios::end);
  streampos fileSize = txt.tellg();
  txt.seekg(0, ios::beg);

  // Allocate memory for the wchar_t buffer
  wchar_t* buffer = new wchar_t[fileSize];

  // Read the file contents into the buffer
  txt.read(buffer, fileSize);

  // Close the file
  txt.close();

  return buffer;
}

void PrintEnd(std::ofstream &output, Vector &Heapp,int counter,string word,int contador_aux){

        output << "FILE" << ":\n\n" << counter << "\n" << "WORD:\n\n" << word << "\n\n" << "FREQUENCIA NO TEXTO:\n\n " << contador_aux <<  "\n" << " HEAP:\n\n "  ;


        for(int i = 0 ; i < MAXSIZE ; i++) {

          string str(Heapp.vet[i].value.begin(),Heapp.vet[i].value.end());
          output << str <<  (str.length() < 8 ? "\t\t\t" :
                str.length() < 16 ? "\t\t\t\t" :
                str.length() < 24 ? "\t\t\t\t\t\t\t\t" :
                str.length() < 32 ? "\t\t\t\t\t\t\t" :
                "\t") << Heapp.vet[i].frequence << "\n";
        }

	output << "\nSIMPLE TREE:\n\n ";

}


//this function print the result for user
std::ofstream createOutput() {
        
        string path;

        path.insert(0, "./dataset/output.data");

	ofstream output(path);

	if (!(output.is_open())) {
          printf("is not possible open the file");
        }
          return output;
        
}



