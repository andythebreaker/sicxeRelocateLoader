#include "pch.h"
#include "input_file_row_vactor_output_t_rec.h"

vector<vector<vector<string>>>* input_file_row_vactor_output_t_rec::t_s_in_all_file = new vector<vector<vector<string>>>();
vector<string>* input_file_row_vactor_output_t_rec::row_t_s_in_all_file = new vector<string>();
vector<string>* input_file_row_vactor_output_t_rec::h = new vector<string>();
vector<string>* input_file_row_vactor_output_t_rec::e = new vector<string>();
int input_file_row_vactor_output_t_rec::total_char_count_in_file_t_rec = 0;
vector < vector < vector <string>>>* input_file_row_vactor_output_t_rec::files_m_stack_per_itmes_loc_mod_fy_ed = new vector<vector<vector<string>>>();
input_file_row_vactor_output_t_rec::input_file_row_vactor_output_t_rec()
{
}


input_file_row_vactor_output_t_rec::~input_file_row_vactor_output_t_rec()
{
}

void input_file_row_vactor_output_t_rec::_(vector<string> vector_string, int addr_margen) {
	vector< vector<string>> t_s_in_single_file;
	vector< vector<string>> m_s_in_single_file;
	int chace_total_char_count_in_file_t_rec = input_file_row_vactor_output_t_rec::total_char_count_in_file_t_rec;
	for (auto &vector_string_pointer : vector_string) {
		const regex re("([T])([A-Za-z0-9]{6})([A-Za-z0-9]{2})(.*)");
		const regex re2("([M])([A-Za-z0-9]{6})([A-Za-z0-9]{2})([\\+\\-])(\\w+)");
		vector<string > sub_t_s_in_single_file;
		vector<string > sub_m_s_in_single_file;
		smatch match;
		smatch match2;
		if (regex_match(vector_string_pointer, match, re))
		{
			row_t_s_in_all_file->push_back(vector_string_pointer);
			debbug cout << "match 1: at " << match.position(1) << " found " << quoted(match[1].str()) << '\n'
				<< "match 2: at " << match.position(2) << " found " << quoted(match[2].str()) << '\n'
				<< "match 3: at " << match.position(3) << " found " << quoted(match[3].str()) << '\n'
				<< "match 4: at " << match.position(4) << " found " << quoted(match[4].str()) << '\n';
			string local_tmp_regex_group_1 = match[1].str();
			string local_tmp_regex_group_2 = match[2].str();
			string local_tmp_regex_group_3 = match[3].str();
			string local_tmp_regex_group_4 = match[4].str();
			HEX_PLUS_INT_EQ_HEX_6(local_tmp_regex_group_2, addr_margen)
				//for (size_t forloop1to4 = 0; forloop1to4 < 4; forloop1to4++)
				//{
				sub_t_s_in_single_file.push_back(local_tmp_regex_group_1);
			sub_t_s_in_single_file.push_back(local_tmp_regex_group_2);
			sub_t_s_in_single_file.push_back(local_tmp_regex_group_3);
			sub_t_s_in_single_file.push_back(local_tmp_regex_group_4);
			//}
			t_s_in_single_file.push_back(sub_t_s_in_single_file);

			//計數整檔案之t字元
			input_file_row_vactor_output_t_rec::total_char_count_in_file_t_rec += local_tmp_regex_group_4.length();
		}
		else if (regex_match(vector_string_pointer, match2, re2)) {
			debbug cout << "match 1: at " << match2.position(1) << " found " << quoted(match2[1].str()) << '\n'
				<< "match 2: at " << match2.position(2) << " found " << quoted(match2[2].str()) << '\n'
				<< "match 3: at " << match2.position(3) << " found " << quoted(match2[3].str()) << '\n'
				<< "match 4: at " << match2.position(4) << " found " << quoted(match2[4].str()) << '\n'
				<< "match 5: at " << match2.position(5) << " found " << quoted(match2[5].str()) << '\n';

			string local_tmp_regex_group_1 = match2[1].str();
			string local_tmp_regex_group_2 = match2[2].str();
			string local_tmp_regex_group_3 = match2[3].str();
			string local_tmp_regex_group_4 = match2[4].str();
			string local_tmp_regex_group_5 = match2[5].str();
			HEX_PLUS_INT_EQ_HEX_6(local_tmp_regex_group_2, chace_total_char_count_in_file_t_rec)
				sub_m_s_in_single_file.push_back(local_tmp_regex_group_1);
			sub_m_s_in_single_file.push_back(local_tmp_regex_group_2);
			sub_m_s_in_single_file.push_back(local_tmp_regex_group_3);
			sub_m_s_in_single_file.push_back(local_tmp_regex_group_4);
			sub_m_s_in_single_file.push_back(local_tmp_regex_group_5);
			m_s_in_single_file.push_back(sub_m_s_in_single_file);
		}
		else {
			cout << "warning @@ void input_file_row_vactor_output_t_rec::_(vector<string> vector_string) {" << endl;
		}
	}
	(*t_s_in_all_file).push_back(t_s_in_single_file);
	(*files_m_stack_per_itmes_loc_mod_fy_ed).push_back(m_s_in_single_file);
}

vector<string> input_file_row_vactor_output_t_rec::get_t_s_in_all_file() {
	vector<string> open_t_s_in_all_file;
	/*for (auto &vector_string_pointer : *(input_file_row_vactor_output_t_rec::t_s_in_all_file)) {
		open_t_s_in_all_file.push_back(&vector_string_pointer);
	}*/
	for (size_t t_s_in_all_file_i = 0; t_s_in_all_file_i < input_file_row_vactor_output_t_rec::t_s_in_all_file->size(); t_s_in_all_file_i++)
	{
		for (int qqq = 0; qqq < ((*(input_file_row_vactor_output_t_rec::t_s_in_all_file))[t_s_in_all_file_i]).size(); qqq++) {
			string tmp = "";
			for (size_t qqi = 0; qqi < ((*(input_file_row_vactor_output_t_rec::t_s_in_all_file))[t_s_in_all_file_i])[qqq].size(); qqi++)
			{
				tmp += ((*(input_file_row_vactor_output_t_rec::t_s_in_all_file))[t_s_in_all_file_i])[qqq][qqi];
			}
			open_t_s_in_all_file.push_back(tmp);
		}
	}
	return open_t_s_in_all_file;
}

void input_file_row_vactor_output_t_rec::add_h_row_t_s_in_all_file() {
	string tmp = "";
	for (auto &vector_string_pointer : *(input_file_row_vactor_output_t_rec::h))
	{
		tmp += vector_string_pointer;
	}
	input_file_row_vactor_output_t_rec::row_t_s_in_all_file->insert(input_file_row_vactor_output_t_rec::row_t_s_in_all_file->begin(), tmp);
}
void input_file_row_vactor_output_t_rec::add_e_row_t_s_in_all_file() {
	string tmp = "";
	for (auto &vector_string_pointer : *(input_file_row_vactor_output_t_rec::e))
	{
		tmp += vector_string_pointer;
	}
	input_file_row_vactor_output_t_rec::row_t_s_in_all_file->push_back(tmp);
}

vector<string> input_file_row_vactor_output_t_rec::m_bar_eat_t_bar() {
	vector<string> forreturn;
	for (auto &vector_string_pointer : *(input_file_row_vactor_output_t_rec::files_m_stack_per_itmes_loc_mod_fy_ed)) {
		for (auto &vector_string_pointer1 : vector_string_pointer) {
			string perrecord = vector_string_pointer1[0]+ vector_string_pointer1[1] + vector_string_pointer1[2];


		}
	}
	return forreturn;
}