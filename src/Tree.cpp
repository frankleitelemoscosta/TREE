#include "Tree.hpp"

Tree_1 *createTree() {
	return NULL;
}

void freeRaiz_1(Tree_1 *tre) {
	if (tre != NULL) {
		freeRaiz_1(tre->esq);
		freeRaiz_1(tre->dir);
		free(tre);
	}
}

void insertItem(Tree_1 **tre, Record_1 r) {
	if (*tre == NULL) {
		*tre = (Tree_1 *)malloc(sizeof(Tree_1));
		(*tre)->esq = NULL;
		(*tre)->dir = NULL;
		(*tre)->reg = r;
		(*tre)->reg.palavras = (Palavras_B*)malloc(20 * sizeof(Palavras_B));

        } else {
		if (r.value < (*tre)->reg.value){
			insertItem(&(*tre)->esq, r);
			}
		else if (r.value > (*tre)->reg.value){
			insertItem(&(*tre)->dir, r);}
		else{
			(*tre)->reg.palavras[(*tre)->reg.quantity].palavra = (char *)malloc(40*sizeof(char));
			(*tre)->reg.palavras[(*tre)->reg.quantity].palavra = r.key;
		    (*tre)->reg.quantity++;

		}
	}
}

void preordem(Tree_1 *tre) {
	if (!(tre == NULL)) {
		std::cout << tre->reg.key << " ";
		preordem(tre->esq);
		preordem(tre->dir);
	}
}

void central(Tree_1 *tre,std::wofstream &output) {
 
  if (!(tre == NULL)) {
    central(tre->esq,output);
    cout << tre->reg.key << "-";
	for(int i = 0 ; i < tre->reg.quantity ; i++)
	{
		cout << tre->reg.palavras[i].palavra << " ";
	} 
    central(tre->dir,output);
	}
}

void posordem(Tree_1 *tre) {
	if (!(tre == NULL)) {
		posordem(tre->esq);
		posordem(tre->dir);
		std::cout << tre->reg.key << " ";
	}
}

void FillingBasicTree(Vector &Heapp,Tree_1 **tre ){

  Record_1 rec;
  string aux_conv_strin;
  char *aux_conv_cha;
  wstring_convert<codecvt_utf8<wchar_t>> converter;

  for(auto item : Heapp.vet)
  {
    aux_conv_strin = converter.to_bytes(item.value);
    
    aux_conv_cha = (char*)malloc((aux_conv_strin.length() + 1)*sizeof(char));

    strcpy(aux_conv_cha, aux_conv_strin.c_str());

	rec.quantity = 0;

    rec.key = aux_conv_cha;
    rec.value = item.frequence;

    insertItem(tre,rec);
  }

}
