#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include<locale>
#include<iostream>
#include <fstream>
#include<map>
#include"Hash.hpp"
#include"Heap.hpp"
#include <dirent.h>
#include <codecvt>

#define MAXFILES 2;

using namespace std;

wchar_t *getText(const locale &loc,int counter);
void PrintEnd(std::ofstream &output, Vector &Heapp,int counter,string word,int contador_aux);
std::ofstream createOutput();

#endif
//end code
