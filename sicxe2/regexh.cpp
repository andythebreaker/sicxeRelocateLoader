#include "pch.h"
#include "regexh.h"

regexh::regexh()
{/*不要呼叫這個，叫(int)的多載*/
	cout << "[ERROR@randoms.cpp::randoms()]" << endl;
	exit(1);
}
regexh::regexh(string hrecord)
{
	cout << "hrecord: " << quoted(hrecord) << '\n';

	const regex re("(H)(.{6})([A-Za-z0-9]{6})([A-Za-z0-9]{6})");

	smatch match;
	if (regex_match(hrecord, match, re))
	{
		cout << "match 1: at " << match.position(1) << " found " << quoted(match[1].str()) << '\n'
			<< "match 2: at " << match.position(2) << " found " << quoted(match[2].str()) << '\n'
			<< "match 3: at " << match.position(3) << " found " << quoted(match[3].str()) << '\n'
			<< "match 4: at " << match.position(4) << " found " << quoted(match[4].str()) << '\n';
		h1 = match[1].str(); h2 = match[2].str(); h3 = match[3].str(); h4 = match[4].str();
	}

	else { cout << "ERROR invalid hrecord\n"; 
	exit(1);
	}
}


regexh::~regexh()
{
}
