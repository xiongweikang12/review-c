#include <stdio.h>
#include <stdlib.h>
#include "amgraph.h"

int Locatevex(ALGraph G, VertexType v)
{
	//根据对应的VertexType 遍历返回index
	for (int index = 0; index < G.vexnum; index++)
	{
		if (G.vertice[index].data==v)
		{
			return index;
		}
		else
		{
			continue;
		}
	}
	return ERROR;
	//寻找失败
}

//创建邻接表
int CreatUDG(ALGraph* G)
{	
	VertexType v1 = '0';
	VertexType v2 = '0';
	int index1 = 0;
	int index2 = 0;
	printf("输入结点数目：");
	scanf_s("%d\n", &(G->vexnum));
	printf("输入边数目：");
	scanf_s("%d\n", &(G->arcnum));
	//输入图的顶点数目，边数目

	for (int i = 0; i < G->vexnum; i++)
	{
		printf("输入顶点值");
		scanf_s("%c\n", &(G->vertice[i].data));
		//输入顶点表信息
		G->vertice->fristarc = NULL;
		//表头置空
	}
	
	for (int k = 0; k < G->arcnum; k++)
	{
		printf("输入结点信息");
		scanf_s("%c\n", &v1);
		printf("输入结点信息");
		scanf_s("%c\n", &v2);
		index1 = Locatevex(*G, v1);
		index2 = Locatevex(*G, v2);
		//根据v1,v2内容得到index

		arcNode* p1 = (arcNode*)malloc(sizeof(arcNode));
		p1->nodeindex = index2;
		p1->next = G->vertice[index1].fristarc;
		G->vertice[index1].fristarc = p1;
		//头插法
		//重复操作
		arcNode* p2 = (arcNode*)malloc(sizeof(arcNode));
		p2->nodeindex = index1;
		p2->next = G->vertice[index2].fristarc;
		G->vertice[index2].fristarc = p2;
	}
	return True;
}
