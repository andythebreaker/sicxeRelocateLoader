#pragma once
#include "Aisatsu.h"
#include <random>
#include <iostream>
#include <map>
#include <cstdlib>
#include <functional>
#include <fstream>
#include <list>
#include <sstream>
#include <fstream>
#define aisatsu_printMEM Aisatsu* Aisatsu0 = new Aisatsu(); Aisatsu0->greeting("print MEM");
#define aisatsu_printEMPTY Aisatsu* Aisatsu1 = new Aisatsu(); Aisatsu1->greeting("");
#define pgsize 4000//4k
using namespace std; 
struct hexd_
{
	string s;
	unsigned int d;
}typedef hexdm;
struct cell_
	{
	hexdm t;
	bool mb;
	hexdm mh;
	int row ;
	int come;
	}typedef cell;
class mems
{
	
public:
	mems(); 
	mems(int main_start);
	mems(int main_start, int reqmem);
	~mems(); 
	map<int, cell> m;
	void print();
	void print2file(string nameo, string sad, int slen, string ta);
	void sethd(hexdm *hd,int i);
};

