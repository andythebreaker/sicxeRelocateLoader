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
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>

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
	regexh* check_hrecord = new regexh(ar_[0]);
	SekaiTekiNi* SekaiTekiNi0 = new SekaiTekiNi();
	SekaiTekiNi0->set(&(SekaiTekiNi0->name), check_hrecord->h2);
	randoms* randoms0 = new randoms(stoul("0x" + check_hrecord->h4, nullptr, 16));
	ostringstream ss;
	ss << hex << randoms0->load_addr;
	SekaiTekiNi0->set(&(SekaiTekiNi0->porgstart), stoul("0x" + check_hrecord->h3, nullptr, 16) == 0 ? ss.str() : check_hrecord->h3);
	SekaiTekiNi0->set(&(SekaiTekiNi0->porglength), check_hrecord->h4);
	SekaiTekiNi0->print();

	mems *mems0 = new mems();
	mems0->print();

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
	rowelement::backward(&vre);
	for (auto &v_re : vre) // access by reference to avoid copying
	{
		v_re.printnew();
	}

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
