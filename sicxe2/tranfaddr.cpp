#include "pch.h"
#include "tranfaddr.h"


tranfaddr::tranfaddr()
{
}

tranfaddr::tranfaddr(string Erecder) {
	cout << "Erecord: " << quoted(Erecder) << '\n';

	const regex re("(E)([A-Za-z0-9]{6})");
	const regex rehw3("(E)");

	smatch match;
	if (regex_match(Erecder, match, re))
	{
		cout << "match 1: at " << match.position(1) << " found " << quoted(match[1].str()) << '\n'
			<< "match 2: at " << match.position(2) << " found " << quoted(match[2].str()) << '\n';
		e1 = match[1].str(); e2 = match[2].str();
	}
	else if (regex_match(Erecder, match, rehw3)) {
		cout << "<blank E>" << endl;
		e1 = "E"; e2 = "999999";
	}
	else {
		cout << "ERROR invalid Erecord\n";
		exit(1);
	}
}

tranfaddr::~tranfaddr()
{
}
