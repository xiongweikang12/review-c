#include "tree.h"
#include <stdio.h>
#include <stdlib.h>



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
void creattree(Tree* T,int tag)
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
		creattree(&((*T)->left),tag);
		creattree(&((*T)->right),tag);
		//��ָ��ȡ��ַ���䵱����ָ��

	}
	(*T)->tag = tag; //��ʾ��ʶλ����ʾ��ʽ
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
		int m = depthtree(T->left) + 1;
		int n = depthtree(T->right) + 1;
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
	if (T->left == NULL && T->right == NULL)
	{
		return 1; //��ʾΪ���ӽڵ� ������һ
	}
	return treeleave_num(T->left) + treeleave_num(T->right);
}

//����һ��tree_nodeָ��
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

//����һ���ֵܵ�ָ��
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
		Treenode* new = (Treenode*)malloc(sizeof(Treenode));//����һ��
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
	//��˳�����������в�������
	for (int i = 2; i < len; i++)//�ӵڶ���λ�ÿ�ʼ
	{
		if (L[i]->data <= L[i - 1]->data)
		{
			//���߱�ǰ��С,�ؼ�����Ϊ�Ƚ�����
			L[0] = L[i];
			int j = i - 1;
			while (L[j]->data > L[0]->data)//
			{
				L[j + 1] = L[j];
				//����ƶ�
				j--;
			}
			//С��ʱ�˳�,�����뵽С��λ�ú�ĵط�
			L[j + 1] = L[0];
		}
	}
}
void ListDelete(Treenode* L[], int index,int len)
{
	/*
	�������
	����Ϊ���
	�����������
	*/
	if (index == len - 1){len--;}
	else
	{	//��������һ�����и��ǣ�ֱ�����
		for (int i = index + 1; i < len; i++)
		{
			L[i - 1] = L[i];
		}
	}
	return 0;
}