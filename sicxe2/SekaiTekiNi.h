#pragma once
#include <string>
#include <regex>
#include <iomanip>
#include <list>
#include <iostream>
#include <fstream>
#include <list>
#include <sstream>

using namespace std;
struct hexd
{
	string s;
	unsigned int d;
};
class SekaiTekiNi
{
public:
	SekaiTekiNi();
	~SekaiTekiNi();
	hexd name;
	hexd porgstart;
	hexd porglength;
	int print();
	unsigned int set(hexd *s,string i);
private:
	//vector<string> global_attribute;
};

