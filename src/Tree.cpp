#include "Tree.hpp"
#include <cstdlib>


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

void central(Tree_1 **tre,std::ofstream &output) {
  

  if (!((*tre) == NULL)) {
    central(&(*tre)->esq,output);
    
	output << (*tre)->reg.key << " " << (*tre)->reg.value << "\n";
	
	for(int i = 0 ; i < (*tre)->reg.quantity ; i++)	
        {
            output << (*tre)->reg.palavras[i].palavra << "-" << (*tre)->reg.value << "\n";
		}
		 
        central(&(*tre)->dir,output);
	}
	
}

void FillingBasicTree(Vector &Heapp, Tree_1 **tre){

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
