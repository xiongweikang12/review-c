#include "tree.h"
#include <stdio.h>
#include <stdlib.h>



//先序
int PreOrderTraverse(Tree T)
{
	if (T == NULL)
	{
		return OK;
	}
	else
	{
		printf("%d\t", T->data);
		PreOrderTraverse(T->left);
		PreOrderTraverse(T->right);
	}
	return OK;
}

//中序
int InOrderTraverse(Tree T)
{
	if (T == NULL)
	{
		return OK;
	}
	else
	{
		InOrderTraverse(T->left);
		printf("%d\t", T->data);
		InOrderTraverse(T->right);
	}
	return OK;
}

//后序
int postOrderTraverse(Tree T)
{
	if (T == NULL)
	{
		return OK;
	}
	else
	{
		postOrderTraverse(T->left);
		postOrderTraverse(T->right);
		printf("%d\t", T->data);
	}
	return OK;
}


/*按照先序建立二叉树二叉链表*/
void creattree(Tree* T,int tag)
{	//通过二级指针，因为树的数据结构在递归中总是对一级指针操作
	//导致一级指针在经过函数后会发生变化
	//通过二级指针操作则避免了

	int data = 0;
	printf("\n输入节点数据:");
	scanf_s("%d", &data);
	if (data == 0)
	{
		(*T) = NULL;
	}
	else
	{
		(*T) = (Treenode*)malloc(sizeof(Treenode));
		(*T)->data = data;
		creattree(&((*T)->left),tag);
		creattree(&((*T)->right),tag);
		//对指针取地址，充当二级指针

	}
	(*T)->tag = tag; //表示标识位，表示方式
	return;

}

//复制
int copytree(Tree T, Tree* NT)
{
	if (T == NULL)
	{
		return OK;
	}
	else
	{
		(*NT)->data = T->data;
		copytree(T->left, &((*NT)->left));
		copytree(T->right, &((*NT)->right));
		return OK;
	}
}

//树的深度
int depthtree(Tree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		int m = depthtree(T->left) + 1;
		int n = depthtree(T->right) + 1;
		return m > n ? m : n;
	}
}

//树的节点数目
int treelnode_num(Tree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		return treelnode_num(T->left) + treelnode_num(T->right) + 1;
	}
}

//叶子节点数目
int treeleave_num(Tree T)
{
	if (T == NULL)
	{
		return 0;
	}
	if (T->left == NULL && T->right == NULL)
	{
		return 1; //表示为孩子节点 ，返回一
	}
	return treeleave_num(T->left) + treeleave_num(T->right);
}

//返回一个tree_node指针
Treenode* return_node(Tree T,const int target_node)
{
	if (T==NULL)
	{
		return NULL;
	}
	else
	{
		if (T->data==target_node)
		{
			return T;
		}
		else
		{
			return_pro(T->left, target_node);
			return_prp(T->right, target_node);
		}
	}
}

//返回一个兄弟的指针
Treenode* return_pro(Tree T, const Treenode* pro)
{
	if (T == NULL)
	{
		return NULL;
	}
	else
	{
		if (T->left==pro)
		{
			return T->right;
		}
		else
		{
			return_pro(T->left, pro);
			return_prp(T->right, pro);
		}
	}
}

void chang_mod(Tree* T)
{

}

Tree build_hf(int* hf_data)
{
	int i = 0;
	int counter = 0;
	int tree_node_num = 0;
	Treenode* all[10];
	while (hf_data[i++]!='/0'){
		all[i]->data = hf_data[i];
		all[i]->left = NULL;
		all[i]->right = NULL;
	}
	tree_node_num = (2 * (i+1)) - 1;
	counter = i;
	Tree new = all[0];
	
	for (int j = counter; j > 2; j--)
	{
		Insert_Sort(all, j);
		Treenode* new = (Treenode*)malloc(sizeof(Treenode));//创建一个
		new->left = all[0];
		new->right = all[1];
		new->data = all[0]->data + all[1]->data;
		ListDelete(all, 0,j);
		ListDelete(all, 1, j);
		all[j] = new;

	}
	return new;
}

void Insert_Sort(Treenode* L[],int len)
{
	//对顺序表操作，进行插入排序
	for (int i = 2; i < len; i++)//从第二个位置开始
	{
		if (L[i]->data <= L[i - 1]->data)
		{
			//后者比前者小,关键字作为比较依据
			L[0] = L[i];
			int j = i - 1;
			while (L[j]->data > L[0]->data)//
			{
				L[j + 1] = L[j];
				//向后移动
				j--;
			}
			//小于时退出,并插入到小于位置后的地方
			L[j + 1] = L[0];
		}
	}
}
void ListDelete(Treenode* L[], int index,int len)
{
	/*
	两种情况
	索引为最后
	索引不在最后
	*/
	if (index == len - 1){len--;}
	else
	{	//从索引后一个进行覆盖，直到最后
		for (int i = index + 1; i < len; i++)
		{
			L[i - 1] = L[i];
		}
	}
	return 0;
}