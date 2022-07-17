#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


//����
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

//����
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

//����
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


/*������������������������*/
void creattree(Tree* T)
{	//ͨ������ָ�룬��Ϊ�������ݽṹ�ڵݹ������Ƕ�һ��ָ�����
	//����һ��ָ���ھ���������ᷢ���仯
	//ͨ������ָ������������

	int data = 0;
	printf("\n����ڵ�����:");
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
		//��ָ��ȡ��ַ���䵱����ָ��

	}
	return;

}

//����
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

//�������
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

//���Ľڵ���Ŀ
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

//Ҷ�ӽڵ���Ŀ
int treeleave_num(Tree T)
{
	if (T == NULL)
	{
		return 0;
	}
	if (T->left==NULL &&T->right==NULL)
	{
		return 1; //��ʾΪ���ӽڵ� ������һ
	}
	return treeleave_num(T->left) + treeleave_num(T->right);
}

