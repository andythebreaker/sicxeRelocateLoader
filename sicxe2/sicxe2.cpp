// sicxe2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"
#include "FILEI.h"
#include "regexh.h"
#include "randoms.h"
#include "Aisatsu.h"
#include "SekaiTekiNi.h"
#include "rowelement.h"
#include "mems.h"
#include "tranfaddr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>

#define VER2
#define aisatsu Aisatsu* Aisatsu0 = new Aisatsu(); Aisatsu0->greeting();
void aisatsu_(std::string aisatsu_word) { Aisatsu* Aisatsu0 = new Aisatsu(); Aisatsu0->greeting(aisatsu_word); }
#define aisatsu91 Aisatsu* Aisatsu91 = new Aisatsu(); Aisatsu91->greeting("questions about in/out put files (type \"EOF\" to abort)");
void aisatsu_91(std::string aisatsu_word) { Aisatsu* Aisatsu91 = new Aisatsu(); Aisatsu91->greeting(aisatsu_word); }
#define aisatsu92 Aisatsu* Aisatsu92 = new Aisatsu(); Aisatsu92->greeting("this is what you just inputed");
void aisatsu_92(std::string aisatsu_word) { Aisatsu* Aisatsu92 = new Aisatsu(); Aisatsu92->greeting(aisatsu_word); }
#define aisatsu93 Aisatsu* Aisatsu93 = new Aisatsu(); Aisatsu93->greeting("now want go into main process");
void aisatsu_93(std::string aisatsu_word) { Aisatsu* Aisatsu93 = new Aisatsu(); Aisatsu93->greeting(aisatsu_word); }
#define set_check_income false
#define set_check_ if(set_check_income)
void check_income(list<string> ar) { aisatsu_("check_income"); for (list<string>::iterator it = ar.begin(); it != ar.end(); it++) { std::cout << *it << endl; }std::cout << "\n"; }

//3 new add
#define PRINTSTRINGVECTOR(stringin) for (std::vector<string>::const_iterator ixxxz = stringin.begin(); ixxxz != stringin.end(); ++ixxxz)std::cout << *ixxxz << " ;";
#define READUSRINPUTCINJUST4WHILELOOP cin >> outputfile_obj_loc;cout << "\n(Information writing confirmation) Your filename is: " << outputfile_obj_loc<<endl;usrinput_locs.push_back(outputfile_obj_loc);counter_tmp_for_while_loop_just_indcate_one++;
#define TESTNOINPUT true

using namespace std;
int main()
{
	aisatsu

		/*flow:
		autoread
		> check H ->?-> exit
		> check name
		> get start loc
		> get length
		> check length ->?-> exit
		*/
		aisatsu91
		vector<string> usrinput_locs;
	string outputfile_obj_loc;
	int counter_tmp_for_while_loop_just_indcate_one = 0;
	if (!TESTNOINPUT) while (outputfile_obj_loc != "EOF")
	{
		if (!counter_tmp_for_while_loop_just_indcate_one) {
			cout << "Type your outputfile (image) name: ";
		}
		else if (counter_tmp_for_while_loop_just_indcate_one == 1)
		{
			cout << "Type your main obj file name: ";
		}
		else {
			cout << "object file name of the subprograms: ";
		}
		READUSRINPUTCINJUST4WHILELOOP
	}
	if (TESTNOINPUT) {
		usrinput_locs.push_back("hw3o.txt");
		usrinput_locs.push_back("hw3inputmain.txt");
		usrinput_locs.push_back("hw3inputsub1.txt");
		usrinput_locs.push_back("hw3inputsub2.txt");
	}
	aisatsu92
		PRINTSTRINGVECTOR(usrinput_locs)
		cout << endl;
	aisatsu93
		int adder_read_all_prog_size = 0;
	for (size_t read_all_prog_size = 1; read_all_prog_size < usrinput_locs.size()-1; read_all_prog_size++)
	{
		cout << usrinput_locs[read_all_prog_size] << endl;

		FILEI* f_tmp = new FILEI();
		list<string> artmp = f_tmp->autoread(usrinput_locs[read_all_prog_size]);
		set_check_ check_income(artmp);
		vector<string> ar_tmp(artmp.size());
		
		copy(artmp.begin(), artmp.end(), ar_tmp.begin());
		
		regexh* check_hrecordtmp = new regexh(ar_tmp[0]);
		
		tranfaddr* tranfaddr0tmp = new tranfaddr(ar_tmp.back());
		
		vector<rowelement> vretmp;
		int rowcounttmp = 0;
		for (list<string>::iterator ittmp = artmp.begin(); ittmp != artmp.end(); ittmp++) {
			if (rowcounttmp && (!(rowcounttmp == artmp.size() - 1))) {
				rowelement *rowelement0tmp = new rowelement(*ittmp);
				vretmp.push_back(*rowelement0tmp);
			}
			rowcounttmp++;
		}
		rowelement::showt(); rowelement::showm();
	}

	FILEI* f_ = new FILEI();
	list<string> ar = f_->autoread();
	set_check_ check_income(ar);
	vector<string> ar_(ar.size());
	copy(ar.begin(), ar.end(), ar_.begin());
	//cout << ar_.back();
	regexh* check_hrecord = new regexh(ar_[0]);
	tranfaddr* tranfaddr0 = new tranfaddr(ar_.back());

	vector<rowelement> vre;
	int rowcount = 0;
	for (list<string>::iterator it = ar.begin(); it != ar.end(); it++) {
		if (rowcount && (!(rowcount == ar.size() - 1))) {
			rowelement *rowelement0 = new rowelement(*it);
			vre.push_back(*rowelement0);
		}
		rowcount++;
	}
	rowelement::showt(); rowelement::showm();

	SekaiTekiNi* SekaiTekiNi0 = new SekaiTekiNi();
	SekaiTekiNi0->set(&(SekaiTekiNi0->name), check_hrecord->h2);
#ifdef VER2
	/*auto it_must_be_h4 = vre[rowelement::rowcount_main_t - 1].startpt.d + vre[rowelement::rowcount_main_t - 1].mt.size() - vre[0].startpt.d;
	cout <<"@@@@@@@@@@@@@@@@@@@@@@@@@"<< it_must_be_h4 << "@@@@@@@@@@@@@@@@@@@@@@@@@"<< check_hrecord->h4 <<"@@@@@@@@@@@@@@@@@"<< endl;
	randoms* randoms0 = new randoms(it_must_be_h4);*/
	randoms* randoms0 = new randoms(vre[rowelement::rowcount_main_t - 1].startpt.d + vre[rowelement::rowcount_main_t - 1].mt.size() - vre[0].startpt.d);
#else // VER1
	randoms* randoms0 = new randoms(stoul("0x" + check_hrecord->h4, nullptr, 16));
#endif // VER
	ostringstream ss;
	ss << hex << randoms0->load_addr;
	SekaiTekiNi0->set(&(SekaiTekiNi0->porgstart), stoul("0x" + check_hrecord->h3, nullptr, 16) == 0 ? ss.str() : check_hrecord->h3);
	SekaiTekiNi0->set(&(SekaiTekiNi0->porglength), check_hrecord->h4);
	//[流程]記憶體布局完成
	SekaiTekiNi0->print();

	/*對VRE做起始元加加
	*/
	for (auto &v_re : vre)
	{
		if (v_re.r == t) {
			ostringstream ss_;
			ss_ << hex << (SekaiTekiNi0->porgstart.d + v_re.startpt.d);
			v_re.set(&(v_re.startpt), ss_.str(), na, -1);
		}
		else if (v_re.r == m) {
			vector<hexdr> newVec(rowelement::t_->begin() + v_re.startpt.d,
				(
					rowelement::t_->begin() + v_re.startpt.d +
					(
					/*(v_re.plen.d % 2 == 0) ? (v_re.plen.d / 2) :*/ ((v_re.plen.d + 1) / 2)
						)
					)
			);

			ostringstream new_Vec;
			bool isfirst = true;
			for (auto &newVec_ : newVec)
			{
				if ((!isfirst)
					||
					(isfirst && (v_re.plen.d % 2 == 0))
					) {

					cout << "#" << newVec_.s << "$";
					reverse(newVec_.s.begin(), newVec_.s.end());
					newVec_.s.resize(2, '0');
					reverse(newVec_.s.begin(), newVec_.s.end());
					new_Vec << newVec_.s;
				}
				else if (isfirst && (v_re.plen.d % 2 != 0)) {
					cout << "#" << newVec_.s << "$";
					reverse(newVec_.s.begin(), newVec_.s.end());
					newVec_.s.resize(2, '0');
					reverse(newVec_.s.begin(), newVec_.s.end());
					new_Vec << newVec_.s[1];
				}
				else {
					cout << "[upper] error!@sicxe2.cpp::<<before>>rowelement::backward(&vre);" << endl;
					exit(1);
				}
				isfirst = false;
			}
			cout << new_Vec.str();
			cout << "%" << endl;
			int thing2add = stoul("0x" + new_Vec.str(), nullptr, 16);
			thing2add += SekaiTekiNi0->porgstart.d;

			ostringstream wb;
			wb << hex << thing2add;
			string wb_ = wb.str();;
			reverse(wb_.begin(), wb_.end());
			wb_.resize(v_re.plen.d, '0');
			reverse(wb_.begin(), wb_.end());
			isfirst = true;
			for (int writeback = 0; writeback < ((v_re.plen.d + 1) / 2); writeback++)
			{
				string tmp_ap = "";
				tmp_ap += ((isfirst && (v_re.plen.d % 2 != 0)) ? (*(rowelement::t_))[v_re.startpt.d + writeback].s[0] : wb_[writeback * 2]);
				tmp_ap += (wb_[writeback * 2 + 1]);
				/*void set(hexdr *z, string i,rt r_t,int rownum_);*/
				cout << "////" << tmp_ap << "////" << endl;
				v_re.set(&((*(rowelement::t_))[v_re.startpt.d + writeback]), tmp_ap
					, (*(rowelement::t_))[v_re.startpt.d + writeback].r_t_, (*(rowelement::t_))[v_re.startpt.d + writeback].rownum);
				isfirst = false;
			}
		}
		else {
			cout << "error!@sicxe2.cpp::<<before>>rowelement::backward(&vre);" << endl;
			exit(1);
		}
	}

	rowelement::backward(&vre);
	vector<int> fmax;
	for (auto &v_re : vre)
	{
		int margen = 0;
		for (auto &v_r_e_ : v_re.new_)
		{
			fmax.push_back(v_re.startpt.d + margen);
			margen++;
		}
	}

	mems *mems0 = new mems(SekaiTekiNi0->porgstart.d,
		vre[rowelement::rowcount_main_t - 1].startpt.d + vre[rowelement::rowcount_main_t - 1].mt.size() - vre[0].startpt.d);
	mems0->print();
	cout << ":::::::::::::::" << mems0->m.size() << endl;
	cout << "max" << *max_element(fmax.begin(), fmax.end()) << endl;//https://stackoverflow.com/questions/34315002/max-in-a-c-array

	for (auto &v_re : vre) // access by reference to avoid copying
	{
		if (v_re.r == t)
		{
			v_re.printnew();
			cout << v_re.startpt.d << endl;
			int margen = 0;
			for (auto &v_r_e_ : v_re.new_) // access by reference to avoid copying
			{
				cout << "[" << (mems0->m).find(v_re.startpt.d + margen)->first << "]" << endl;
				mems0->sethd(&((mems0->m).find(v_re.startpt.d + margen)->second.t), v_r_e_.d);
				cout << (v_re.startpt.d + margen) << "<" << v_r_e_.s << "> ";
				margen++;
			}
		}
	}
	mems0->print();
	mems0->print2file(SekaiTekiNi0->name.s, SekaiTekiNi0->porgstart.s,
		(vre[rowelement::rowcount_main_t - 1].startpt.d + vre[rowelement::rowcount_main_t - 1].mt.size() - vre[0].startpt.d)
		, tranfaddr0->e2 == "000000" ? SekaiTekiNi0->porgstart.s : tranfaddr0->e2);

	exit(0);
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的秘訣: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
