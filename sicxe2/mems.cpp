#include "pch.h"
#include "mems.h"


mems::mems()
{
	for (size_t i = 0; i < pgsize; i++)
	{
		cell tc;
		tc.mb = false;
		tc.row = -1;
		sethd(&(tc.mh), 0);
		sethd(&(tc.t), 0);

	m.insert(map<int, cell>::value_type(i,tc));
	}
}
void mems::sethd(hexdm *hd,int i) {
	(*hd).d = i;
	ostringstream ss;
	ss << hex << i;
	(*hd).s = ss.str();
}
void mems::print() {
	cout << endl;
	int ix = 0;
		for (map<int, cell>::iterator it = m.begin(); it != m.end(); it++) { 
			cout << (*it).second.t.s ;
			ix++;
			if (ix % 64 == 0)cout << endl;
		}
}


mems::~mems()
{
}
