#ifndef HEAP_H 
#define HEAP_H

#include"Hash.hpp"
#include<iostream>
#include<sstream>
#include<locale>
#include<vector>
#include<unordered_map>

#define MAXSIZE 20

using namespace std;

typedef struct Vector Vector;
typedef struct Itens Itens;


struct Itens{

	int frequence;
	wstring value;

};

struct Vector{

	//Itens *vet;
	vector<Itens> vet;

};

void FillingHeap(Vector &Heapp,Hashh &mp,wstring wstr);
void Heapfy(Vector &Heapp);


#endif
