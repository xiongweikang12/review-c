
#include "tree_child.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>



int init_tree_child(tree_child* T_c)
{
	//给分配空间
	T_c->c_tree = (struct cbox*)malloc(sizeof(struct cbox)*Maxsize);
	T_c->num = 0;
	return 1;
}

int creat_tree__child(tree_child* T_c)
{
	init_tree_child(T_c);
	char temp = '0';
	char input_info = '0';
	while (1)
	{
		printf("please input info of tree:");
		input_info = getchar();  //换行也计入了，需要解决。
		temp = getchar();
		if (input_info!='k')
		{
			T_c->c_tree[T_c->num++].info = input_info;
			printf("\n");
		}
		else
		{
			break;
		}
		

	}
	T_c->num++;
	printf("%d \n", T_c->num);
	return 1;
}

int build_child_tree(tree_child* T_c)
{
	int flag_node_next = 1;
	for (int i = 0; i < T_c->num; i++)
	{
		printf("please input flag_node_next：");
		scanf_s("%d", &flag_node_next);
		if (flag_node_next==1){}
		else 
		{ T_c->c_tree->frist_child = NULL;
			continue;
		}
		int flag = 1; 
		int child_index = -1;
		tree_child_node* rear = T_c->c_tree->frist_child;
		while (flag)
		{
			tree_child_node* child_node = (tree_child_node*)malloc(sizeof(tree_child_node));
			printf("please input index:");
			while (1)
			{
				scanf_s("%d", &child_index);
				if (child_index <= T_c->num && child_index >= 0) { break; }
				else { continue; }
			}
			child_node->child_index = child_index;
			// T_c->c_tree->frist_child = child_node;
			rear = child_node;
			child_node->next_child = NULL;
			printf("please input flag:");
			scanf_s("%d", &flag); //flag非0 表示还孩子，0表示结束
		}
	}

	return 0;
}

int return_child(tree_child* C_T, char target_node, char* child_node_return)
{
	int count = 0;
	for (int i = 0; i < C_T->num; i++)
	{
		if (C_T->c_tree[i].info == target_node) {
			tree_child_node*  op_pointer= (tree_child_node*)malloc(sizeof(tree_child_node));
			op_pointer = C_T->c_tree[i].frist_child;
			while (op_pointer)
			{
				child_node_return[count++] = C_T->c_tree[op_pointer->child_index].info;
				op_pointer = op_pointer->next_child;
			}
		}
		else
		{
			continue;
		}
	}
	return count + 1;
}