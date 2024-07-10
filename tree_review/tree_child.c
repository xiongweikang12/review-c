
#include "tree_child.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>



int _stdcall init_tree_child(tree_child* T_c)
{
	//给分配空间
	T_c->num = 0;
	return 1;
}

int _stdcall creat_tree__child(tree_child* T_c)
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
			T_c->c_tree[T_c->num].info = input_info;
			T_c->c_tree[T_c->num].frist_child = NULL;
			T_c->num++;
			printf("\n");
		}
		else
		{
			break;
		}
	}
	printf("%d \n", T_c->num);
	return 1;
}

int _stdcall build_child_tree(tree_child* T_c)
{
	int flag_node_next = 1;
	for (int i = 0; i < T_c->num; i++)
	{
		int counter = 0;
		printf("please input flag_node_next：");
		scanf_s("%d", &flag_node_next);
		if (flag_node_next!=0){}
		else 
		{ T_c->c_tree[i].frist_child = NULL; //正确的逻辑部分
			continue;
		}
		int flag = 1; 
		int child_index = -1;
		tree_child_node* rear = T_c->c_tree[i].frist_child;
		while (flag)
		{
			tree_child_node* child_node = (tree_child_node*)malloc(sizeof(tree_child_node));
			child_node->next_child = NULL;
			printf("please input index:");
			while (1)
			{
				scanf_s("%d", &child_index);
				if (child_index <= T_c->num && child_index >= 0 && child_index!=i) { break; }
				else { continue; }
			}
			child_node->child_index = child_index;
			if (counter == 0) { T_c->c_tree[i].frist_child = child_node; }
			else { counter++; }
			child_node->next_child = rear;
			rear = child_node;
			printf("please input flag:");
			scanf_s("%d", &flag); //flag非0 表示还有孩子，0表示结束
		}

	}

	return 0;
}

int _stdcall return_child(tree_child* C_T, const char target_node, char* child_node_return)
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
	return count;
}

tree_child_box _stdcall return_parent(tree_child *CT, const char target_node)
{
	//根据target_node,及孩子节点，找到双亲 //注意双亲是唯一的
	for (int i = 0; i <CT->num; i++)
	{
		if (CT->c_tree[i].frist_child != NULL)
		{
			tree_child_node *op_pointer= (tree_child_node*)malloc(sizeof(tree_child_node));
			op_pointer = CT->c_tree[i].frist_child;
			while (op_pointer)
			{
				if (target_node == CT->c_tree[op_pointer->child_index].info)
				{
					return CT->c_tree[i];
				}
				op_pointer = op_pointer->next_child;
			}
		}
		else
		{
			continue;
		}
	}

}