#include <stdio.h>
#include "amgraph.h"

int Locatevex(AMGraph G, VertexType v)
{
	//根据对应的VertexType 遍历返回index
	for (int index = 0; index < G.vexnum; index++)
	{
		if (G.ves[index]==v)
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

int CreatUDN(AMGraph *G)
{
	// int veaxnum = 0;
	// int arcnum = 0;
	int index1 = 0;
	int index2 = 0;

	printf("输入顶点数目");
	scanf_s("%d\n", &(G->vexnum));
	printf("输入边数目");
	scanf_s("%d\n", &(G->arcnum));
	//输入顶点数目
	//输入边的数目

	//遍历访问辅助表初始化
	for (int i = 0; i < G->vexnum; i++)
	{
		printf("输入顶点表");
		scanf_s("%c\n", &(G->ves[i]));
		G->visited[i] = 0;
	}
	//输入顶点表信息
	for (int k = 0; k < G->vexnum; k++)
	{
		for (int j = 0; j<G->arcnum; j++)
		{
			G->arcs[k][j] = 0;
		}
	}
	//初始化临边矩阵
	VertexType v1 = 'i';
	VertexType v2 = 'o';
	for (int v = 0; v < G->arcnum; v++)
	{
		printf("输入顶点");
		scanf_s("%c\n", &v1);
		printf("输入顶点");
		scanf_s("%c\n", &v2);
		int index1 = Locatevex(*G, v1);
		int index2 = Locatevex(*G, v2);
	}
	//根据VertexType的到索引
	G->arcs[index1][index2] = 1; //表示权数wi
	G->arcs[index2][index1] = G->arcs[index1][index2];
	//联系两个顶点，输入边权
	return True;
}
