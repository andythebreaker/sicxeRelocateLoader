#pragma once
#include <random>
#include <iostream>
#include <map>
#include <cstdlib>
#include <functional>
#include <fstream>
#include <list>
#include <sstream>
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
	~mems();
	map<int, cell> m;
	void print();
	void sethd(hexdm *hd,int i);
};

