#pragma once
#include "Aisatsu.h"
#include <random>
#include <iostream>
#include <map>
#include <cstdlib>
#include <functional>
#include <fstream>
#include <list>
#include <sstream>
#include <regex>
#include <iomanip>

#define aisatsu_afterbackward Aisatsu* Aisatsu0 = new Aisatsu(); Aisatsu0->greeting("after reloacted");
#define aisatsu_showm Aisatsu* Aisatsu1 = new Aisatsu(); Aisatsu1->greeting("showm");
#define aisatsu_showt Aisatsu* Aisatsu2 = new Aisatsu(); Aisatsu2->greeting("showt");
#define setting_debbug false
#define debbug if(setting_debbug)

using namespace std;
enum recordtype
{
	t,m,na
}typedef rt;
struct hex_d_
{
	string s;
	unsigned int d;
	int rownum;
	rt r_t_;
}typedef hexdr;
class rowelement
{
public:
	rowelement();
	~rowelement();
	rt r;
	vector<string> s;
	rowelement(string i);
	string p1; string p4; string p3; string p2;
	hexdr startpt;
	hexdr plen;
	vector<hexdr> mt;
	//static vector<hexdr> all;
	//static vector<hexdr> tmp_;
	static vector<hexdr>* m_;
	static vector<hexdr>* t_;
	static void showm();
	static void showt();
	static void backward(vector<rowelement>* v_r_e);
	vector<hexdr> new_;
	void printnew();
	int start_index; int end_index;
private:
	void set(hexdr *z, string i,rt r_t,int rownum_);
	static int rowcount_main_t; static int rowcount_main_m;
	static vector<hexdr>* row_loc_start;
};

