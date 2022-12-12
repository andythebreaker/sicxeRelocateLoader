#pragma once
#include <random>
#include <iostream>
using namespace std;
class randoms
{
public:
	randoms();
	randoms(int progsize);
	int load_addr;
	~randoms();
private:
	int min;
	int max;
	int pages;
	int pnum;
};

