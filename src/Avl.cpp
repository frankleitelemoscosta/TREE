#include "Avl.hpp"

Tree_AVL *createTree_AVL() { return NULL; }

void insertItem_AVL(Tree_AVL **t, Record_AVL iteM) {
	if (*t == NULL) {
		*t = (Tree_AVL *)malloc(sizeof(Tree_AVL));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->item = iteM;
		(*t)->peso = 0;
		(*t)->item.palavras = (Palavras*)malloc(20 * sizeof(Palavras));

	} else if (iteM.value < (*t)->item.value) {
		insertItem_AVL(&(*t)->esq, iteM);

		if (getPeso(&(*t)->esq) - getPeso(&(*t)->dir) == 2) {
			if (iteM.value < (*t)->esq->item.value)
				rotacaoSimplesDireita_AVL(t);
			else
				rotacaoDuplaDireita_AVL(t);
		}
	} else if (iteM.value > (*t)->item.value) {
		insertItem_AVL(&(*t)->dir, iteM);

		if (getPeso(&(*t)->dir) - getPeso(&(*t)->esq) == -2) {
			if (iteM.key > (*t)->dir->item.key)
				rotacaoSimplesEsquerda_AVL(t);
			else
				rotacaoDuplaEsquerda_AVL(t);
		}
	}else{
			(*t)->item.palavras[(*t)->item.quantity].palavra = (char *)malloc(40*sizeof(char));
			(*t)->item.palavras[(*t)->item.quantity].palavra = iteM.key;
		    (*t)->item.quantity++;

		}
	(*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
}


void rebalancear_AVL(Tree_AVL **t) {
	int delta;

	delta = getPeso(&(*t)->esq) - getPeso(&(*t)->dir);

	if (delta == 2) {
		if (getPeso(&(*t)->esq->esq) >= getPeso(&(*t)->esq->dir)) {
			rotacaoSimplesDireita_AVL(t);
		} else {
			rotacaoDuplaDireita_AVL(t);
		}
	} else if (delta == -2) {
		if (getPeso(&(*t)->dir->dir) >= getPeso(&(*t)->dir->esq)) {
			rotacaoSimplesEsquerda_AVL(t);
		} else {
			rotacaoDuplaEsquerda_AVL(t);
		}
	}
}

void central_AVL(Tree_AVL *t,std::ofstream &output) {
	

	if (!(t == NULL)) {
		central_AVL(t->esq,output);
		string str(t->item.key);
		output << str << (str.length() < 8 ? "\t\t\t\t" :
                str.length() < 16 ? "\t\t\t" :
                str.length() < 24 ? "\t\t\t" :
                str.length() < 32 ? "\t\t\t\t\t\t\t" :
                "\t") << t->item.value << "\n";
	        for(int i = 0 ; i < t->item.quantity ; i++)
	        {
	  	    output << t->item.palavras[i].palavra <<  (str.length() < 8 ? "\t\t\t\t" :
                str.length() < 16 ? "\t\t\t" :
                str.length() < 24 ? "\t\t\t\t\t" :
                str.length() < 32 ? "\t\t\t\t\t\t\t" :
                "\t") <<  t->item.value <<"\n";
	        }
                central_AVL(t->dir,output);
	}
}

int getPeso(Tree_AVL **t) {
	return (*t == NULL) ? -1 : (*t)->peso;
}

int getMaxPeso(int left, int right) {
	return (left > right) ? left : right;
}

void rotacaoSimplesDireita_AVL(Tree_AVL **t) {
	Tree_AVL *aux;

	aux = (*t)->esq;
	cout << "Peso:" << (*t)->esq->peso << "\t |Chave:" << (*t)->esq->item.key << "\t |Quantidade de palavras com a mesma frequencia:" << (*t)->esq->item.quantity<<endl;
	(*t)->esq = aux->dir;
	aux->dir = *t;
	(*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
	aux->peso = getMaxPeso(getPeso(&aux->esq), (*t)->peso) + 1;
	*t = aux;
}

void rotacaoSimplesEsquerda_AVL(Tree_AVL **t) {
	Tree_AVL *aux;

	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = *t;
	(*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
	aux->peso = getMaxPeso(getPeso(&aux->dir), (*t)->peso) + 1;
	*t = aux;
}

void rotacaoDuplaDireita_AVL(Tree_AVL **t) {
	rotacaoSimplesEsquerda_AVL(&(*t)->esq);
	rotacaoSimplesDireita_AVL(t);
}

void rotacaoDuplaEsquerda_AVL(Tree_AVL **t) {
	rotacaoSimplesDireita_AVL(&(*t)->dir);
	rotacaoSimplesEsquerda_AVL(t);
}
void free_AVL(Tree_AVL *t) {
	if (t != NULL) {
		free_AVL(t->esq);
		free_AVL(t->dir);
		free(t);
	}
}

void FillingAvl(Vector &Heapp,Tree_AVL **avl)
{
  Record_AVL record;
  string aux_conv_strin;
  char *aux_conv_cha;
  wstring_convert<codecvt_utf8<wchar_t>> converter;


  for(auto item : Heapp.vet)
  {
   aux_conv_strin = converter.to_bytes(item.value);
    
    aux_conv_cha = (char*)malloc((aux_conv_strin.length() + 1)*sizeof(char));

    strcpy(aux_conv_cha, aux_conv_strin.c_str());

    record.quantity = 0;

    record.key = aux_conv_cha;
    record.value = item.frequence;

    insertItem_AVL(avl,record);

  }

}
