#include "pch.h"
#include "rdr.h"

rdr::rdr()
{/*不要呼叫這個，叫(int)的多載*/
	cout << "[ERROR@rdr.cpp::rdr()]" << endl;
	exit(1);
}

rdr::rdr(vector<string> xrdx)
{
	const regex re("([RD])(.+)");
	for (vector<string>::iterator it = xrdx.begin(); it != xrdx.end(); it++) {
		Aisatsu* Aisatsu91 = new Aisatsu(); Aisatsu91->greeting(*it);
		smatch match;
	if (regex_match(*it, match, re))
	{
		cout << "match 1: at " << match.position(1) << " found " << quoted(match[1].str()) << '\n'
			<< "match 2: at " << match.position(2) << " found " << quoted(match[2].str()) << '\n';
			//<< "match 3: at " << match.position(3) << " found " << quoted(match[3].str()) << '\n'
		//<< "match 4: at " << match.position(4) << " found " << quoted(match[4].str()) << '\n';
		h1 = match[1].str(); h2 = match[2].str();// h3 = match[3].str(); h4 = match[4].str();
		for (string::iterator it2 = h2.begin(); it2 != h2.end(); it2++) {
			cout << *it2 << "*****";
		}
		if (h1=="R")
		{
			
		}
		else if (h1 == "D")
		{

		}
		else
		{
			cout << "[ERROR] not a R or D rec." << endl;
			exit(1);
		}
	}
	else {
	//	cout << "ERROR invalid r/drecord\n";
		//exit(1);
		cout << "not a R or D rec." << endl;
	}
	}
}


rdr::~rdr()
{
}
