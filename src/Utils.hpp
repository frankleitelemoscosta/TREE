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
void printStart(std::wofstream &output);
std::wofstream createOutput(const std::locale &loc);
void printEnd(Vector *v);


#endif
//end code