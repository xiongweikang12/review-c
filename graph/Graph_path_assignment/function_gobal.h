

#ifndef Graph_test_sysfuntion
#define Graph_test_sysfunction
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define Maxsize 12
typedef string* string_point;

//�ַ��������Զ����
string* fill_label(int size_graph);
//�ı��ַ����������
void change_fill_label(const string_point& source_label, string_point& fill_label, int size_);

void map_vector_tomat(map<vector<int>,float> source_flow, float Graph_mat_flowtype[Maxsize][Maxsize]);

void show_vector(vector<int> path);

#endif // !Graph_test_sysfuntion
