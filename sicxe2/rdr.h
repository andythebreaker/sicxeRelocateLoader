#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <fstream>
#include <list>
#include <sstream>
#include <algorithm>
#include <map>

#include "Aisatsu.h"

using namespace std;
class rdr
{
public:
	rdr();
	rdr(vector<string> xdr,int startpt);
	string h1; string h2; string h3; string h4;
	~rdr();
	static map<string, int>* varmap;
};

