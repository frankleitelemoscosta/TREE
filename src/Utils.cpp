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

//this function print the result for user
void printEnd(Vector &Heapp, std::wofstream &output)
{

  output << L"File"<< L"\t\t\t|"<< L"Palavra" << L"\t\t\t|" << L"Contagem de frequencia no texto" <<  L"\t\t\t|" << L"\n";


   for(int i = 0 ; i < MAXSIZE ; i++) {

      output << L"\t\t\t\t" << Heapp.vet[i].value << L"\t\t\t\t"<< Heapp.vet[i].frequence << L"\n";
   }


   output << L"======================================================================================================================================\n";
}

std::wofstream createOutput(const std::locale &loc)
{
  wofstream output("./dataset/output.data");

  if(!output.is_open()) {
    wcout << L"Não foi possível abrir o arquivo \"./dataset/output.data\"" << endl;
    exit(1);
  }

  output.imbue(loc);

  return output;
}

void printStart(std::wofstream &output)
{
	output << L"======================================================================================================================================\n"
					  L"=>                                                    ### START PROCESS ###\n"
	          L"======================================================================================================================================\n"
            L"\n";
}
