#pragma once
#include "pch.h"
#include "./FILEI.h"
#include <iostream>
#include <fstream>//[or ifstream](https://www.w3schools.com/cpp/cpp_files.asp)
#include<string>//[debg](https://stackoverflow.com/questions/27755191/getline-identifier-not-found)
#include <list>
using namespace std;
class FILEI
{
public:
	FILEI();
	~FILEI();
	list<string> autoread();
};

