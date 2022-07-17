#include "parent_tree.h"
#include <stdio.h>
#include <stdlib.h>


//构建双亲树
int Creatpr_tree(PTree* PT)
{
	PT->r = 0;
	int index = 0;
	int content = 0;
	int index_node = 0;
	// PT->node->parent = index_node;
	while (1)
	{	
		printf("输入节点内容:");
		scanf_s("%d", &content);
		if (content==-1)
		{	

			break;
		}
		else
		{
			printf("输入parent");
			scanf_s("%d", &index);
			PT->node[index_node].data = content;
			PT->node[index_node++].parent = index;
			continue;
		}
	}
	PT->n = index_node;
	if (PT->n>MAX_TREE_SIZE)
	{
		return 0;
	}
	return 1;
}

//通过遍历寻找双亲节点
PTnode search_ptnode(int content, PTree* PT)
{	
	PTnode *ReturnNode = (PTnode*)malloc(sizeof(PTnode));
	for (int index = 0; index < PT->n; index++)
	{
		if (PT->node[index].data == content) //表示找到 ,elemtype
		{
			if (PT->node[index].parent!=-1)
			{
				return PT->node[PT->node[index].parent]; //返回双亲
			}
			else
			{
				ReturnNode->data = -1;
				ReturnNode->parent = -1;
				return *ReturnNode;
			}
		}
		else
		{
			continue;
		}
	}
}