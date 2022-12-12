#include "pch.h"
#include "rowelement.h"

vector<hexdr>* rowelement::m_ = new vector<hexdr>(); vector<hexdr>* rowelement::t_ = new vector<hexdr>();
int rowelement::rowcount_main_t = -1; int rowelement::rowcount_main_m = -1;
vector<hexdr>* rowelement::row_loc_start = new vector<hexdr>();
rowelement::rowelement()
{
}
void rowelement::showm() {
	for (vector<hexdr>::iterator it = (*m_).begin(); it != (*m_).end(); it++) {
		cout << "," << (*it).s << ";";
	}
}void rowelement::showt() {
	for (vector<hexdr>::iterator it = (*t_).begin(); it != (*t_).end(); it++) {
		cout << "," << (*it).s << ";";
	}
}

rowelement::rowelement(string i)
{
	cout << "xrecord: " << quoted(i) << '\n';

	const regex re("([TM])([A-Za-z0-9]{6})([A-Za-z0-9]{2})(.+)");

	smatch match;
	if (regex_match(i, match, re))
	{
		cout << "match 1: at " << match.position(1) << " found " << quoted(match[1].str()) << '\n'
			<< "match 2: at " << match.position(2) << " found " << quoted(match[2].str()) << '\n'
			<< "match 3: at " << match.position(3) << " found " << quoted(match[3].str()) << '\n'
			<< "match 4: at " << match.position(4) << " found " << quoted(match[4].str()) << '\n';
		p1 = match[1].str(); p2 = match[2].str(); p3 = match[3].str(); p4 = match[4].str();
		r = (p1 == "T") ? t : m;
		if (r == m)rowcount_main_m++;
		if (r == t)rowcount_main_t++;
		if (r == t)start_index = t_->size(); //rowelement::rowcount_main_t;
		cout << "rt" << r << endl;
		set(&plen, p3, na, -1);
		cout << "plen" << plen.d << endl;
		cout << "p4 len" << p4.length() << endl;
		hexdr tmp_;
		set(&tmp_, p2, na, -1);
		(*row_loc_start).push_back(tmp_);
		if (plen.d * 2 != p4.length()) {
			cout << "[error] record len NEQ!" << endl;
			exit(1);
		}
		string::iterator lc = p4.begin();
		for (size_t j = 1; j <= p4.length() / 2; j++)
		{
			string::iterator  aa = (j + 1 > p4.length() / 2) ? (p4.end()) : (p4.begin() + 2 * j);
			string bb(lc, aa);
			//cout << bb << endl;
			lc = aa;
			hexdr tmp;
			set(&tmp, bb, r, (r == t) ? rowcount_main_t : rowcount_main_m);
			mt.push_back(tmp);
			if (r == m)(*m_).push_back(tmp);
			if (r == t)(*t_).push_back(tmp);
		}
		/*int rowcount = 0;
		for (vector<hexdr>::iterator it = mt.begin(); it != mt.end(); it++) {
			cout << "," << (*it).s << ";";
			rowcount++;
		}*/
		if (r == t)end_index = t_->size();
	}

	else {
		cout << "ERROR invalid xrecord\n";
		exit(1);
	}
}
void rowelement::set(hexdr *z, string i, rt r_t, int rownum_) {
	(*z).s = i;
	(*z).d = stoul("0x" + i, nullptr, 16);
	(*z).rownum = rownum_;
	(*z).r_t_ = r_t;
	(*z).rownum = rownum_;
}
void rowelement::backward(vector<rowelement>* v_r_e) {
	//foreach vre
	for (vector<rowelement>::iterator it = (*v_r_e).begin(); it != (*v_r_e).end(); it++) {
		//std::cout << *it << endl;
	//讀使末位址int start_index; int end_index;
		cout << "Z?" << (*it).r << endl;
		//向總取資料
		if ((*it).r == t) {
			cout << "WHAT" << (*it).start_index <<"--"<< (*it).end_index << endl;
			for (int k = (*it).start_index; k < (*it).end_index; k++)
			{
				(*it).new_.push_back((*t_)[k]);
				cout << "debug" << (*t_)[k].s << endl;
			}
		}
	}

}

void rowelement::printnew() {
	cout << "\n" << "~";
	for (auto &h_exdr : new_) // access by reference to avoid copying
	{
		cout << h_exdr.s << "^";
	}
}

//void rowelement::print() {
	//for (vector<hexdr>::iterator it = rowelement::all.begin(); it != rowelement::all.end(); it++) {
//		cout << /*"," << (*it).s <<*/ ";";
	//}
//}

rowelement::~rowelement()
{
}
