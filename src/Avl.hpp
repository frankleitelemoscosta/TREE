#ifndef AVL_HPP
#define AVL_HPP

#include <stdio.h>
#include <stdlib.h>
#include "Heap.hpp"
#include <codecvt>
#include <string>
#include<iostream>
#include <cstring>

using namespace std;

typedef struct Record_AVL Record_AVL;
typedef struct Tree_AVL Tree_AVL;
typedef struct Palavras Palavras;

struct Palavras
{
	char *palavra;
};


struct Record_AVL {
	int value;
	char *key;
	int quantity;
	Palavras *palavras;
};

struct Tree_AVL {
	Record_AVL item;
	Tree_AVL *esq, *dir;
	int peso;
};

Tree_AVL *createTree_AVL();

void insertItem_AVL(Tree_AVL **t, Record_AVL r);
void removeItem_AVL(Tree_AVL **t, Tree_AVL **f, Record_AVL item);

void preordem_AVL(Tree_AVL *t);
void central_AVL(Tree_AVL *t);
void posordem_AVL(Tree_AVL *t);

int getPeso(Tree_AVL **t);
int getMaxPeso(int left, int right);

void rotacaoSimplesDireita_AVL(Tree_AVL **t);
void rotacaoSimplesEsquerda_AVL(Tree_AVL **t);
void rotacaoDuplaDireita_AVL(Tree_AVL **t);
void rotacaoDuplaEsquerda_AVL(Tree_AVL **t);

void free_AVL(Tree_AVL *t);

void FillingAvl(Vector &Heapp,Tree_AVL **t);

#endif
