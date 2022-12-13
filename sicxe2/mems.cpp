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
	//cout << "*******************************" << reqmem;
	int first_run = 0;
	int check_safe_mem_size = 0;
	int icatch = 0;
	while (!(check_safe_mem_size > reqmem))
	{
		//cout << "***********check_safe_mem_size***********" << check_safe_mem_size;
		//cout << "(((((((((((((((" << ((first_run == 0) ? main_start : icatch) << ")))))))))))))))))))))))";
		//cout << "(((((((((((((((" << (((first_run == 0) ? main_start : icatch) + pgsize) << ")))))))))))))))))))))))";
		int ibuff = -1;
		for (int i = (first_run == 0) ? main_start : icatch; i < (((first_run == 0) ? main_start : icatch) + pgsize); i++)
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
		icatch = ibuff + 1;
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
		string tmp2l = (*it).second.t.s.length() == 2 ? (*it).second.t.s : ("0" + (*it).second.t.s);
		cout << tmp2l;
		ix++;
		if (ix % /*64*/32 == 0)cout << endl;
	}
	cout << endl;
	aisatsu_printEMPTY
}

void mems::print2file(string nameo, string sad, int slen, string ta) {
	//string text = "Hello, world!";
	ostringstream ss;
	ss << hex << slen;
	string l_hd_s = ss.str();
	nameo.resize(6, ' ');
	reverse(sad.begin(), sad.end());
	sad.resize(6, '0');
	reverse(sad.begin(), sad.end());
	reverse(l_hd_s.begin(), l_hd_s.end());
	l_hd_s.resize(6, '0');
	reverse(l_hd_s.begin(), l_hd_s.end());
	reverse(ta.begin(), ta.end());
	ta.resize(6, '0');
	reverse(ta.begin(), ta.end());
	// Create an output stream to write to the file
	ofstream out_file("DEVF2");
	out_file << "I";
	out_file << nameo;
	out_file << sad;
	out_file << l_hd_s;
	out_file << ta;
	out_file << endl;
	// Write the string to the file
	//out_file << text << endl;
	int ix = 0;
	for (map<int, cell>::iterator it = m.begin(); it != m.end(); it++) {
		string tmp2l = (*it).second.t.s.length() == 2 ? (*it).second.t.s : ("0" + (*it).second.t.s);
		out_file << tmp2l;
		ix++;
		if (ix % /*64*/32 == 0)out_file << endl;
	}
	// Close the file
	out_file.close();
}

mems::~mems()
{
}
