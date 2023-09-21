#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include"Heap.hpp"
#include<codecvt>
#include<string>
#include<fstream>

using namespace std;

typedef struct Item Item;
typedef struct Huffman Huffman;
typedef struct Forest Forest;

struct Item{

	char *word;
	int frequence;
	int controle;
};

struct Huffman{
	Item item;
	Huffman *left;
	Huffman*right;

};
	

bool SizeCompare(Huffman *a,Huffman *b);
void Preordem(Huffman *H,std::ofstream &output);
void ConstructHuffman(vector<Huffman*> &H,std::ofstream &output);
void FillingHuffman(Vector &Heapp,std::ofstream &output);
Huffman *CreateHuffman();
void InsertHuffman(Huffman **H,Item I);

#endif
