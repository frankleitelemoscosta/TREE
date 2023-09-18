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

using namespace std;

typedef struct Record_1 Record_1;
typedef struct Tree_1 Tree_1;

struct Record_1 {
	int value;
	char *key;
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
void central(Tree_1 *tre);
void posordem(Tree_1 *tre);

void FillingBasicTree(Vector &Heapp,Tree_1 **tre );

#endif
