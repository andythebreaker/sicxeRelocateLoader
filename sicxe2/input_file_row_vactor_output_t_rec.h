#pragma once
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

#define setting_debbug true
#define debbug if(setting_debbug)
#define HEX_PLUS_INT_EQ_HEX_6(o6O_string,O6o_int) string oooOOOooo1 = o6O_string;int oooOOOooo2 = O6o_int;int oooOOOooo3 = stoul("0x" + oooOOOooo1, nullptr, 16) + oooOOOooo2;ostringstream oooOOOooo4;oooOOOooo4 << hex << oooOOOooo3;string oooOOOooo5 = oooOOOooo4.str();reverse(oooOOOooo5.begin(), oooOOOooo5.end());oooOOOooo5.resize(oooOOOooo1.length(), '0');reverse(oooOOOooo5.begin(), oooOOOooo5.end());transform(oooOOOooo5.begin(), oooOOOooo5.end(), oooOOOooo5.begin(), ::toupper);o6O_string=oooOOOooo5;
#define HEX_PLUS_MINUS_INT_EQ_HEX_6(o6O_string,O6o_int,OOO_plus_mins_str) string oooOOOooo1 = o6O_string;int oooOOOooo2 = (O6o_int)*(((OOO_plus_mins_str)=="+")?1:-1);int oooOOOooo3 = stoul("0x" + oooOOOooo1, nullptr, 16) + oooOOOooo2;ostringstream oooOOOooo4;oooOOOooo4 << hex << oooOOOooo3;string oooOOOooo5 = oooOOOooo4.str();reverse(oooOOOooo5.begin(), oooOOOooo5.end());oooOOOooo5.resize(oooOOOooo1.length(), '0');reverse(oooOOOooo5.begin(), oooOOOooo5.end());transform(oooOOOooo5.begin(), oooOOOooo5.end(), oooOOOooo5.begin(), ::toupper);o6O_string=oooOOOooo5;
using namespace std;
class input_file_row_vactor_output_t_rec
{
public:
	input_file_row_vactor_output_t_rec();
	~input_file_row_vactor_output_t_rec();
	static void _(vector<string> vector_string, int addr_margen);
	static vector<string> get_t_s_in_all_file();
	static vector<string>* row_t_s_in_all_file;
	static vector<string>* h;
	static vector<string>* e;
	static void add_h_row_t_s_in_all_file();
	static void add_e_row_t_s_in_all_file();
	static int total_char_count_in_file_t_rec;
	static vector < vector < vector <string>>>* files_m_stack_per_itmes_loc_mod_fy_ed;
	static vector<string> m_bar_eat_t_bar();
private:
	static vector<vector<vector<string>>>* t_s_in_all_file;
};

