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

void ConstructHuffman(vector<Huffman*> &H)
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
		bool key = false;
		bool keytwo = false;
		/*item.frequence = left->item.frequence + Rigth->item.frequence;
		item.word = (char*)malloc(20 * sizeof(char));
		strcpy(item.word,"$");*/
		//Huffman *aux = CreateHuffman();
		Huffman *aux = (Huffman*)malloc(sizeof(Huffman));
		//InsertHuffman(&aux,item);
		if(left->item.controle == 0)
		{
			key = true;
		}
		if(Rigth->item.controle == 0)
		{
			keytwo = true;
		}
		aux->left = left;
		aux->right = Rigth;
		aux->right->item.controle = aux->right->item.controle ;
		aux->item.frequence = left->item.frequence + Rigth->item.frequence;
		aux->item.controle = 1;
		if (keytwo == true)aux->right->item.controle = 0;
		if(key == true)aux->left->item.controle = 0;

		H.erase(H.begin());
		H.erase(H.begin());

		H.push_back(aux);
		//H.pop_back();

	}

	Preordem(H[0]);
	cout<<endl;

}

void Preordem(Huffman *H)
{
	if(H != NULL)
	{
		if(H->item.controle != 1) {cout << H->item.frequence<<endl;}
		
	      //cout << H->item.controle << " "<< H->item.frequence<<endl;
		Preordem(H->left);
		Preordem(H->right);
	}
}
