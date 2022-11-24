
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "function_gobal.h"


using namespace std;
typedef string* string_point;
typedef float** float_double_pointer;

//可以将这些全局函数改为模板函数

string* fill_label(int size_graph)
{
	//将对象的label按照字符填充
	auto return_string_list = new string[size_graph];
	for (int i = 0; i < size_graph; i++)
	{
		return_string_list[i] = to_string(i+1);
	}
	return return_string_list;
}


void change_fill_label(const string_point& source_label, string_point& fill_label, int size_)
{
	//保证长度覆盖,更改图中点的对应标签
	for (int i = 0; i < size_; i++)
	{
		fill_label[i] = source_label[i];
	}
}

void map_vector_tomat(map<vector<int>,float> source_flow, float Graph_mat_flowtype[Maxsize][Maxsize])
{
	//首先 Graph_flow_type 是 图流量的矩阵形式
	//其需要初始化置零，也就是说调用前需要初始化一次
	for (auto i : source_flow)
	{
		auto index_row = i.first[0]-1;
		auto index_col = i.first[1]-1;
		auto double_part_flow = i.second;
		Graph_mat_flowtype[index_row][index_col] = double_part_flow;
	}
}

void show_vector(vector<int> path)
{
	cout << "short_path" << endl;
	for (auto i : path)
	{
		cout << i << "->";
	}
}
