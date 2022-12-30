#include "pch.h"
#include "rdr.h"

map<string, int>* rdr::varmap = new map<string, int>();

rdr::rdr()
{/*不要呼叫這個，叫(int)的多載*/
	cout << "[ERROR@rdr.cpp::rdr()]" << endl;
	exit(1);
}

rdr::rdr(vector<string> xrdx,int startpt)
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
			cout << "[info] i just dont want to do r data struct XD" << endl;
		}
		else if (h1 == "D")
		{
			//string str("0123456789asdf");
			vector<string> sixsplit;
			for (unsigned i = 0; i < h2.length(); i += 6) {
				string tmp_sixsplit = h2.substr(i, 6);
				sixsplit.push_back(tmp_sixsplit);
				cout << tmp_sixsplit << endl;
			}
			//map<string, int> varmap;
			for (size_t sixsplit_group_2 = 0; sixsplit_group_2 < sixsplit.size(); sixsplit_group_2++)
			{
				string removenamespce = sixsplit[sixsplit_group_2];
				removenamespce.erase(remove_if(removenamespce.begin(), removenamespce.end(), isspace), removenamespce.end());

				if (sixsplit_group_2 % 2 == 0) {
					varmap->insert(pair<string, int>(removenamespce, startpt + stoul("0x" + sixsplit[sixsplit_group_2 + 1], nullptr, 16)));
				}
			}
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
