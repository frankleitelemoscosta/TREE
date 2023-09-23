#include "Huffman.hpp"

Huffman *CreateHuffman()
{
	return NULL;
}

bool SizeCompare(Huffman *a,Huffman *b)
{
	return a->item.frequence < b->item.frequence;
}

void InsertHuffman(Huffman **H,Item I)
{
	(*H) = (Huffman*)malloc(sizeof(Huffman));
	(*H)->left = NULL;
	(*H)->right = NULL;
	(*H)->item.frequence = I.frequence;
	(*H)->item.word = (char*)malloc(30 * sizeof(char));
	strcpy((*H)->item.word,I.word);
}

void FillingHuffman(Vector &Heapp,std::ofstream &output)
{
  Item I;
  Huffman *huf = CreateHuffman();
  char *aux_conv_cha;
  string aux_conv_strin;
  wstring_convert<codecvt_utf8<wchar_t>> converter;
  vector<Huffman*> vec;


  for(auto H : Heapp.vet)
  {
    I.word = (char*)malloc(50 * sizeof(char));

    aux_conv_strin = converter.to_bytes(H.value);
    aux_conv_cha = (char*)malloc((aux_conv_strin.length() + 1)*sizeof(char));
    strcpy(aux_conv_cha, aux_conv_strin.c_str());


    I.word = aux_conv_cha;
    I.frequence = H.frequence;

    InsertHuffman(&huf,I);

    vec.push_back(huf);

    free(I.word);
  }
  ConstructHuffman(vec,output);
}

void ConstructHuffman(vector<Huffman*> &H,std::ofstream &output)
{
    for(int i = 0; i < H.size() ; i++)
    {
        H[i]->item.controle = 0;
    }


	while(H.size() > 1)
	{
	sort(H.begin(),H.end(),SizeCompare);
		//cout << H[0]->item.frequence<< " "<< H[1]->item.frequence <<" "<<H.size()<<endl;
		Huffman *left = H[0];
		Huffman *Rigth = H[1];
		Huffman *aux = (Huffman*)malloc(sizeof(Huffman));
		aux->left = left;
		aux->right = Rigth;
		aux->right->item.controle = aux->right->item.controle ;
		aux->item.frequence = left->item.frequence + Rigth->item.frequence;
		aux->item.controle = 1;

		H.erase(H.begin());
		H.erase(H.begin());

		H.push_back(aux);
		//H.pop_back();

	}

	Preordem(H[0],output);
	cout<<endl;

}

void Preordem(Huffman *H,std::ofstream &output)
{
	if(H != NULL)
	{
		if(H->item.controle != 1) {output << H->item.word << H->item.frequence<<endl;}
		
		//cout << H->item.controle << " "<< H->item.frequence<<endl;
		Preordem(H->left,output);
		Preordem(H->right,output);
	}
}
