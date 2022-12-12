#pragma once
#include <iostream>
#include <string>
using namespace std;
#ifdef __linux__ 
//linux code goes here
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#elif _WIN32
// windows code goes here
#include <windows.h>
#else

#endif


class Aisatsu
{
public:
	Aisatsu();
	~Aisatsu();
	void greeting();
	void greeting(string midword);
private:
	int Tcolumns;
	int Trows;
	string consts_;
	int consth;
};

