#include "huff_array.h"
#include <stdio.h>
#include <stdlib.h>

void _stdcall CreatHuffmanTree(Huff_tree HT, int n)
{
	if (n<=1){return;}
	int m = (2 * n) - 1;
	int input = 0;
	HT = (Huff_tree)malloc(sizeof(Huff_node) * (m + 1)); //�����ռ�
	for (int i = 1; i < m; i++)
	{
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	}
	for (int i = 1; i < m; i++)
	{
		printf("input a num:");
		scanf_s("%d", &input);
		printf("\n");
		HT[i].weight = input;
	}
	//��ʼ����
	for (int i = n+1; i < m; i++)
	{
		//ѡ���������С��Ԫ��
	}

}