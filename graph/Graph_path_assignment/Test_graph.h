
#ifndef Graph_test
#define Graph_test
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include "function_gobal.h"
using namespace std;
#define Maxsize 12
#define INF 10000

class Graph_test_flow
{
public:


	Graph_test_flow(int size_):Graph_size(size_){
		memset(Graph_catity,0, sizeof(Graph_catity));
		Graph_label = fill_label(Graph_size);
		memset(Graph_flow_assignment, 0, sizeof(Graph_flow_assignment));
		memset(Graph_flow_matType, 0, sizeof(Graph_flow_matType));
	};

	Graph_test_flow():Graph_size(0){
		memset(Graph_catity,0, sizeof(Graph_catity));
		Graph_label = fill_label(Graph_size);
		memset(Graph_flow_assignment, 0, sizeof(Graph_flow_assignment));
		memset(Graph_flow_matType, 0, sizeof(Graph_flow_matType));
	};
	Graph_test_flow(int Graph_size,float **Graph_ci,map<vector<int>,float> Graph_flow)
	:Graph_size(Graph_size),Graph_flow(Graph_flow)
	{
		Graph_label = fill_label(Graph_size);
		memset(Graph_flow_assignment,0, sizeof(Graph_flow_assignment));
		memset(Graph_flow_matType, 0, sizeof(Graph_flow_matType));
		
	}
	bool is_legal_object(); 
	//判断是否合法
	//大小一样和Graph_size
	
	inline int getGraph_size()
	{
		return Graph_size;
	}

	void show_Graph_label();
	void show_Graph_catity();
	void show_Graph_flow();
	void show_Graph_flow_matType();
	void show_Graph_flow_assignment();
	void set_Graph_flow(map<vector<int>, float> set_flow);
	void Graph_flow_Trun();
	void init_Graph_catity();
	void set_Graph_catity(const float[Maxsize][Maxsize]);
	vector<string> short_path(int start,int end, bool is_label);
	//返回最小路径
	void set_Graph_label(const string_point source);


	


private:

	int Graph_size; //图的大小
	float Graph_catity[Maxsize][Maxsize]; //图的路径
	map<vector<int>, float> Graph_flow; //图的流量
	float Graph_flow_assignment[Maxsize][Maxsize]; //流量分配
	string *Graph_label; //图的标签
	float Graph_flow_matType[Maxsize][Maxsize];//图流量的矩阵形式

};










#endif // !Graph_test
