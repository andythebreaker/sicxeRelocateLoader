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
#define set_check_income false
#define set_check_ if(set_check_income)
void check_income(list<string> ar) { aisatsu_("check_income"); for (list<string>::iterator it = ar.begin(); it != ar.end(); it++) { std::cout << *it << endl; }std::cout << "\n"; }

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
	randoms* randoms0 = new randoms(vre[rowelement::rowcount_main_t - 1].startpt.d+vre[rowelement::rowcount_main_t-1].mt.size()- vre[0].startpt.d);
#else // VER1
	randoms* randoms0 = new randoms(stoul("0x" + check_hrecord->h4, nullptr, 16));
#endif // VER
	ostringstream ss;
	ss << hex << randoms0->load_addr;
	SekaiTekiNi0->set(&(SekaiTekiNi0->porgstart), stoul("0x" + check_hrecord->h3, nullptr, 16) == 0 ? ss.str() : check_hrecord->h3);
	SekaiTekiNi0->set(&(SekaiTekiNi0->porglength), check_hrecord->h4);
	SekaiTekiNi0->print();

	/*對VRE做起始元加加
	*/
	for (auto &v_re : vre)
	{
		ostringstream ss_;
		ss_ << hex << (SekaiTekiNi0->porgstart.d + v_re.startpt.d);
		v_re.set(&(v_re.startpt), ss_.str(),na,-1);
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
	cout<<":::::::::::::::"<<mems0->m.size()<<endl;
	cout <<"max"<< *max_element(fmax.begin(), fmax.end()) << endl;//https://stackoverflow.com/questions/34315002/max-in-a-c-array

	for (auto &v_re : vre) // access by reference to avoid copying
	{
		if (v_re.r==t)
		{
		v_re.printnew();
		cout << v_re.startpt.d << endl;
		int margen = 0;
		for (auto &v_r_e_ : v_re.new_) // access by reference to avoid copying
		{
			cout << "["<<(mems0->m).find(v_re.startpt.d + margen)->first <<"]"<< endl;
			mems0->sethd(&((mems0->m).find(v_re.startpt.d + margen)->second.t), v_r_e_.d);
			cout << (v_re.startpt.d + margen) << "<" << v_r_e_.s << "> ";
			margen++;
		}
		}
	}
	mems0->print();
	mems0->print2file(SekaiTekiNi0->name.s, SekaiTekiNi0->porgstart.s,
		(vre[rowelement::rowcount_main_t - 1].startpt.d + vre[rowelement::rowcount_main_t - 1].mt.size() - vre[0].startpt.d)
		,tranfaddr0->e2=="000000"?SekaiTekiNi0->porgstart.s:tranfaddr0->e2);

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
