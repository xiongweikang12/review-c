#include <stdio.h>
#include "amgraph.h"

//深度优先遍历
void DFS(AMGraph G, int v)
{
	G.visited[v] = True;
	for (int i = 0; i <G.vexnum; i++)
	{
		if ((G.arcs[v][i]!=0)&&(!G.visited[i])) //表示为顶点而且未被访问
		{
			DFS(G, i); //递归思想，深度（一直找下去）
		}
	}
}

//入队算法
void adjListEN(QadjList *Q, VNode v)
{
	Q->ad[Q->R++] = v;
	//将VNode放入其中然后指针后移动
}

//出队算法
VNode outnode(QadjList* Q)
{
	VNode return_node = Q->ad[Q->F++];
	return return_node;
}

int QueneEmpty(QadjList Q)
{
	if (Q.F==Q.R)
	{
		return 0;
	}
	else
	{
		return 1;

	}
}


//广度优先遍历(用邻接表表示)
void BFS(ALGraph G, int v)
{
	G.visited[v] = True;//表示访问
	QadjList *Q;
	VNode getout;
	adjListEN(Q, G.vertice[v]);//表示入队
	// arcNode* oper = G.vertice[v].fristarc;
	while (!QueneEmpty(*Q))
	{	
		getout = outnode(Q);
		arcNode* oper = getout.fristarc;
		while (oper)
		{	
			//判断是否访问过
			if (G.visited[oper->nodeindex] == 0)
			{
				adjListEN(Q, G.vertice[oper->nodeindex]);
				//对于没有访问过的入队
			}
			oper = oper->next;
			//操作指针移动
			//表示将邻接表的链表部分入队
		}
	}
	
}


