#include <stdio.h>
#include <stdlib.h>
#include "amgraph.h"

int Locatevex(ALGraph G, VertexType v)
{
	//���ݶ�Ӧ��VertexType ��������index
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
	//Ѱ��ʧ��
}

//�����ڽӱ�
int CreatUDG(ALGraph* G)
{	
	VertexType v1 = '0';
	VertexType v2 = '0';
	int index1 = 0;
	int index2 = 0;
	printf("��������Ŀ��");
	scanf_s("%d\n", &(G->vexnum));
	printf("�������Ŀ��");
	scanf_s("%d\n", &(G->arcnum));
	//����ͼ�Ķ�����Ŀ������Ŀ

	for (int i = 0; i < G->vexnum; i++)
	{
		printf("���붥��ֵ");
		scanf_s("%c\n", &(G->vertice[i].data));
		//���붥�����Ϣ
		G->vertice->fristarc = NULL;
		//��ͷ�ÿ�
	}
	
	for (int k = 0; k < G->arcnum; k++)
	{
		printf("��������Ϣ");
		scanf_s("%c\n", &v1);
		printf("��������Ϣ");
		scanf_s("%c\n", &v2);
		index1 = Locatevex(*G, v1);
		index2 = Locatevex(*G, v2);
		//����v1,v2���ݵõ�index

		arcNode* p1 = (arcNode*)malloc(sizeof(arcNode));
		p1->nodeindex = index2;
		p1->next = G->vertice[index1].fristarc;
		G->vertice[index1].fristarc = p1;
		//ͷ�巨
		//�ظ�����
		arcNode* p2 = (arcNode*)malloc(sizeof(arcNode));
		p2->nodeindex = index1;
		p2->next = G->vertice[index2].fristarc;
		G->vertice[index2].fristarc = p2;
	}
	return True;
}
