#include "function_gobal.h"
#include "Test_graph.h"
#include "function_gobal_template.h"
#include <stack>

bool Graph_test_flow::is_legal_object()
{
	return Graph_size <= Maxsize;
}

void Graph_test_flow::show_Graph_label()
{	
	cout <<"\n"<< "Grahp_label:" << endl;
	show_fill_label(Graph_label, Graph_size);

}

void Graph_test_flow::show_Graph_catity()
{
	cout <<"\n"<< "Graph_catity" << endl;
	show_mat(Graph_catity, Graph_size);
}

void Graph_test_flow::show_Graph_flow_assignment()
{
	cout << "\n" << "show_Graph_flow_assignment" << endl;
	show_mat(Graph_flow_assignment, Graph_size);
}

void Graph_test_flow::set_Graph_flow(map<vector<int>, float> set_flow)
{
	for (auto i : set_flow)
	{
		Graph_flow.insert({ i.first,i.second });
	}
}

void Graph_test_flow::show_Graph_flow()
{
	cout << "\n" << "Graph_flow_:" << endl;
	for (auto i : Graph_flow)
	{
		cout << i.first[0] << "->" << i.first[1] << ":" << i.second << endl;
	}
}

void Graph_test_flow::Graph_flow_Trun()
{
	cout <<"\n"<< "Graph_flow_Trun_mat" << endl;
	map_vector_tomat(Graph_flow, Graph_flow_matType);

}

void Graph_test_flow::show_Graph_flow_matType()
{
	cout <<"\n" << "show Graph_flow_matType" << endl;
	show_mat(Graph_flow_matType, Graph_size);
}

void Graph_test_flow::init_Graph_catity()
{
	cout <<"\n"<<"init_Graph_catity" << endl;
	fill_INF(Graph_catity, INF, Graph_size);
}

void Graph_test_flow::set_Graph_catity(const float soure[Maxsize][Maxsize])
{
	cout <<"\n"<< "set_Graph_catitiy" << endl;
	set_mat(soure, Graph_catity,Graph_size);
}

void Graph_test_flow::set_Graph_label(const string_point source)
{
	cout << "|n" << "set_Graph_label" << endl;
	change_fill_label(source, Graph_label,Graph_size);
}

vector<string> Graph_test_flow::short_path(int start,int end,bool is_label)
{
	int j, k, w, m, n = Graph_size;
	bool* s = new bool[n];
	int dist[Maxsize];
	int path[Maxsize];
	for (j = 0; j < n; j++)
	{
		if (j == start)
		{
			s[j] = true;
		}
		else
		{
			s[j] = false;
		}
		dist[j] = Graph_catity[start][j];
		if (dist[j] < INF && j != start)
		{
			path[j] = start;
		}
		else
		{
			path[j] = -1;
		}
	}

	for (k = 1; k < n - 1; k++)
	{
		w = INF;
		m = start;
		for (j = 0; j < n; j++)
		{
			if (s[j] == false && dist[j] < w)
			{
				w = dist[j];
				m = j;
			}
		}

		if (m != start)
		{
			s[m] = true;
		}
		else
		{
			break;
		}

		for (j = 0; j < n; j++)
		{
			if (s[j] == false && dist[m] + Graph_catity[m][j] < dist[j])
			{
				dist[j] = dist[m] + Graph_catity[m][j];
				path[j] = m;
			}
		}
	}
	int index = end;
	stack<int> short_path_stack;
	vector<string> short_path_vector_label;
	vector<int> short_path_vector;

	while (index!=start)
	{
		if (index==end)
		{
			short_path_stack.push(end);
		}
		else
		{
			short_path_stack.push(index);
		}
		index = path [index];
	}
	short_path_stack.push(start);
	while (short_path_stack.empty()==false)
	{
		
		short_path_vector_label.push_back(Graph_label[short_path_stack.top()]);
		short_path_vector.push_back(short_path_stack.top());
		short_path_stack.pop();
	}

	//Á÷Á¿·ÖÅä
	vector<int> start_end = { start,end };
	float flow_path = Graph_flow[start_end];
	for (int i = 0; i < short_path_vector.size()-1; i++)
	{
		Graph_flow_assignment[short_path_vector[i]][short_path_vector[i + 1]] += flow_path;
	}

	delete[] s;
	cout << "\n" << "Graph_short_path:" << endl;
	return short_path_vector_label;
}