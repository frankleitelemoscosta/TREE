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
		(*tre)->reg.palavras = (Palavras*)malloc(20 * sizeof(Palavras));

        } else {
		if (r.value < (*tre)->reg.value){
			insertItem(&(*tre)->esq, r);
			}
		else if (r.value > (*tre)->reg.value){
			insertItem(&(*tre)->dir, r);}
		else{
			printf("igual: %s - %d\n", r.key, r.value);
			(*tre)->reg.palavras[(*tre)->reg.quantity].palavra = (char *)malloc(40*sizeof(char));
			(*tre)->reg.palavras[(*tre)->reg.quantity].palavra = r.key;
		    (*tre)->reg.quantity++;

		}
	}
}

void pesquisa(Tree_1 **tre, Tree_1 **aux, Record_1 r) {
	if (*tre == NULL) {
		printf("[ERRO]: Node not found!\n");
		return;
	}

	if ((*tre)->reg.key < r.key) { pesquisa(&(*tre)->esq, aux, r); return; }
	if ((*tre)->reg.key > r.key) { pesquisa(&(*tre)->dir, aux, r); return; }

	*aux = *tre;
}

void antecessor(Tree_1 **tre, Tree_1 *aux) {
	if ((*tre)->dir != NULL) {
		antecessor(&(*tre)->dir, aux);
		return;
	}

	aux->reg = (*tre)->reg;
	aux = *tre;
	*tre = (*tre)->esq;
	free(aux);
}

void removeItem(Tree_1 **tre, Record_1 r) {
	Tree_1 *aux;

	if (*tre == NULL) {
		printf("[ERROR]: Record_1 not found!!!\n");
		return;
	}

	if ((*tre)->reg.key > r.key) { removeItem(&(*tre)->esq, r); return; }
	if ((*tre)->reg.key < r.key) { removeItem(&(*tre)->dir, r); return; }

	if ((*tre)->dir == NULL) {
		aux = *tre;
		*tre = (*tre)->esq;
		free(aux);
		return;
	}

	if ((*tre)->esq != NULL) {
		antecessor(&(*tre)->esq, *tre);
		return;
	}

	aux = *tre;
	*tre = (*tre)->dir;
	free(aux);
}

void preordem(Tree_1 *tre) {
	if (!(tre == NULL)) {
		// printf("%d ", t->reg.key);
		std::cout << tre->reg.key << " ";
		preordem(tre->esq);
		preordem(tre->dir);
	}
}

void central(Tree_1 *tre) {
 
  if (!(tre == NULL)) {
    central(tre->esq);
    cout << tre->reg.key << "-";
	for(int i = 0 ; i < tre->reg.quantity ; i++)
	{
		cout << tre->reg.palavras[i].palavra << " ";
	}cout << "\n";
    central(tre->dir);
	}
}

void posordem(Tree_1 *tre) {
	if (!(tre == NULL)) {
		posordem(tre->esq);
		posordem(tre->dir);
		// printf("%d ", t->reg.key);
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
