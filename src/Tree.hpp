#ifndef TREE_HPP
#define TREE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Heap.hpp"
#include <iostream>
#include <codecvt>
#include <string>
#include <cstring>
#include<vector>
#include <fstream>
#include <locale>

using namespace std;

typedef struct Record_1 Record_1;
typedef struct Tree_1 Tree_1;
typedef struct Palavras_B Palavras_B;

struct Palavras_B
{
    char *palavra;
};


struct Record_1 {
	int value;
	char *key;
	int quantity;
	Palavras_B *palavras;
};

struct Tree_1 {
	Record_1 reg;
	Tree_1 *esq, *dir;
};

Tree_1 *createTree();
void insertItem(Tree_1 **tre, Record_1 r);
void pesquisa(Tree_1 **tre, Tree_1 **aux, Record_1 r);

void antecessor(Tree_1 **tre, Tree_1 *aux);
void removeItem(Tree_1 **tre, Record_1 r);
void freeRaiz_1(Tree_1 *tre);

void preordem(Tree_1 *tre);
void central(Tree_1 **tre,std::ofstream &output);
void posordem(Tree_1 *tre);

void FillingBasicTree(Vector &Heapp,Tree_1 **tre );

#endif
