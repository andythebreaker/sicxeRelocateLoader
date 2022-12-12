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

		m.insert(map<int, cell>::value_type(i, tc));
	}
}
mems::mems(int main_start)
{
	//cout << "::::::::::::::::::::::::::::::::::" << main_start << endl;
	for (int i = main_start; i < main_start + pgsize; i++)
	{
		cell tc;
		tc.mb = false;
		tc.row = -1;
		sethd(&(tc.mh), 0);
		sethd(&(tc.t), 255);//FF

		m.insert(map<int, cell>::value_type(i, tc));
	}
	//cout << "::::::::::::::::::::::::::::::::::" <<( main_start + pgsize )<< endl;
}

mems::mems(int main_start, int reqmem)
{
	cout << "*******************************" << reqmem;
	int first_run = 0;
	int check_safe_mem_size = 0;
	int icatch = 0;
	while (!(check_safe_mem_size > reqmem))
	{
		//cout << "***********check_safe_mem_size***********" << check_safe_mem_size;
		//cout << "(((((((((((((((" << ((first_run == 0) ? main_start : icatch) << ")))))))))))))))))))))))";
		//cout << "(((((((((((((((" << (((first_run == 0) ? main_start : icatch) + pgsize) << ")))))))))))))))))))))))";
	int ibuff = -1;
		for (int i = (first_run==0)?main_start: icatch; i <(( (first_run==0) ? main_start : icatch) + pgsize); i++)
		{
			cell tc;
			tc.mb = false;
			tc.row = -1;
			sethd(&(tc.mh), 0);
			sethd(&(tc.t), 255);//FF

			m.insert(map<int, cell>::value_type(i, tc));
			check_safe_mem_size++;
			ibuff = i;
			//cout << check_safe_mem_size << " "<<i << endl;
		}
		first_run++; 
		icatch=ibuff+1;
	}
}

void mems::sethd(hexdm *hd, int i) {
	(*hd).d = i;
	ostringstream ss;
	ss << hex << i;
	(*hd).s = ss.str();
}
void mems::print() {
	cout << endl;
	aisatsu_printMEM
		int ix = 0;
	for (map<int, cell>::iterator it = m.begin(); it != m.end(); it++) {
		string tmp2l = (*it).second.t.s.length()==2? (*it).second.t.s:("0"+ (*it).second.t.s);
		cout << tmp2l;
		ix++;
		if (ix % /*64*/32 == 0)cout << endl;
	}
	cout << endl;
	aisatsu_printEMPTY
}


mems::~mems()
{
}
