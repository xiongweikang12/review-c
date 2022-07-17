#include <stdio.h>
#include "amgraph.h"

int Locatevex(AMGraph G, VertexType v)
{
	//���ݶ�Ӧ��VertexType ��������index
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
	//Ѱ��ʧ��
}

int CreatUDN(AMGraph *G)
{
	// int veaxnum = 0;
	// int arcnum = 0;
	int index1 = 0;
	int index2 = 0;

	printf("���붥����Ŀ");
	scanf_s("%d\n", &(G->vexnum));
	printf("�������Ŀ");
	scanf_s("%d\n", &(G->arcnum));
	//���붥����Ŀ
	//����ߵ���Ŀ

	//�������ʸ������ʼ��
	for (int i = 0; i < G->vexnum; i++)
	{
		printf("���붥���");
		scanf_s("%c\n", &(G->ves[i]));
		G->visited[i] = 0;
	}
	//���붥�����Ϣ
	for (int k = 0; k < G->vexnum; k++)
	{
		for (int j = 0; j<G->arcnum; j++)
		{
			G->arcs[k][j] = 0;
		}
	}
	//��ʼ���ٱ߾���
	VertexType v1 = 'i';
	VertexType v2 = 'o';
	for (int v = 0; v < G->arcnum; v++)
	{
		printf("���붥��");
		scanf_s("%c\n", &v1);
		printf("���붥��");
		scanf_s("%c\n", &v2);
		int index1 = Locatevex(*G, v1);
		int index2 = Locatevex(*G, v2);
	}
	//����VertexType�ĵ�����
	G->arcs[index1][index2] = 1; //��ʾȨ��wi
	G->arcs[index2][index1] = G->arcs[index1][index2];
	//��ϵ�������㣬�����Ȩ
	return True;
}
