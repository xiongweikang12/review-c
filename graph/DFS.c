#include <stdio.h>
#include "amgraph.h"

//������ȱ���
void DFS(AMGraph G, int v)
{
	G.visited[v] = True;
	for (int i = 0; i <G.vexnum; i++)
	{
		if ((G.arcs[v][i]!=0)&&(!G.visited[i])) //��ʾΪ�������δ������
		{
			DFS(G, i); //�ݹ�˼�룬��ȣ�һֱ����ȥ��
		}
	}
}

//����㷨
void adjListEN(QadjList *Q, VNode v)
{
	Q->ad[Q->R++] = v;
	//��VNode��������Ȼ��ָ����ƶ�
}

//�����㷨
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


//������ȱ���(���ڽӱ��ʾ)
void BFS(ALGraph G, int v)
{
	G.visited[v] = True;//��ʾ����
	QadjList *Q;
	VNode getout;
	adjListEN(Q, G.vertice[v]);//��ʾ���
	// arcNode* oper = G.vertice[v].fristarc;
	while (!QueneEmpty(*Q))
	{	
		getout = outnode(Q);
		arcNode* oper = getout.fristarc;
		while (oper)
		{	
			//�ж��Ƿ���ʹ�
			if (G.visited[oper->nodeindex] == 0)
			{
				adjListEN(Q, G.vertice[oper->nodeindex]);
				//����û�з��ʹ������
			}
			oper = oper->next;
			//����ָ���ƶ�
			//��ʾ���ڽӱ�����������
		}
	}
	
}


