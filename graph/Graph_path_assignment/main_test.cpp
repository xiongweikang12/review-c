#include "function_gobal.h"
#include "function_gobal_template.h"
#include <iostream>
using namespace std;
#include "Test_graph.h"

int main()
{
	auto ii = fill_label(4);

	/*for (int i = 0; i < 4; i++)
	{
		cout << ii[i] << "->";
	}
	cout << "\n" << "->";*/

	show_fill_label(ii,4);
	cout << "\n";
	string array[] = {"A","B","C","D"};
	change_fill_label(array, ii,4);
	show_fill_label(ii,4);
	Graph_test_flow a(4);
	cout << "\n";
	a.show_Graph_label();
	a.set_Graph_label(array);
	a.show_Graph_label();
	a.init_Graph_catity();
	a.show_Graph_catity();

	vector<int> test1 = { 1,2 };
	vector<int> test2 = { 0,2 };
	map<vector<int>, float> test_flow;
	test_flow.insert({test1,100.0 });
	test_flow.insert({test2,200.0 });
	a.set_Graph_flow(test_flow);
	a.show_Graph_flow();

	a.Graph_flow_Trun();
	a.show_Graph_flow_matType();

	float arr[Maxsize][Maxsize] = 
	{ {0,1,4,3},{INF,0,2,INF},{INF,INF,0,INF},{INF,INF,INF,0} };
	a.set_Graph_catity(arr);
	a.show_Graph_catity();
	
	/*
	for (auto i : short_path)
	{
		cout << i << "->";
	}
	*/
	
	for (auto i:a.get_flow())
	{
		auto start=i.first[0];
		auto end=i.first[1];
		auto short_path = a.short_path(start,end, true);
		cout << start << "->" << end << "\t" << ":";
		for (auto j : short_path)
		{
		cout << j << "->";
		}
		
		
	}
	
	a.show_Graph_flow_assignment();

	

	delete[] ii;
	return 0;

}

