#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


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
void creattree(Tree* T)
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
		creattree(&((*T)->left));
		creattree(&((*T)->right));
		//对指针取地址，充当二级指针

	}
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
		int m = depthtree(T->left)+1;
		int n = depthtree(T->right)+1;
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
	if (T->left==NULL &&T->right==NULL)
	{
		return 1; //表示为孩子节点 ，返回一
	}
	return treeleave_num(T->left) + treeleave_num(T->right);
}

