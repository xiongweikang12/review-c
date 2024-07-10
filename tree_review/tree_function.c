#include "tree.h"
#include <stdio.h>
#include <stdlib.h>



//����
int _stdcall PreOrderTraverse(Tree T)
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
int _stdcall InOrderTraverse(Tree T)
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
int _stdcall postOrderTraverse(Tree T)
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
void _stdcall creattree(Tree* T,int tag)
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
int _stdcall copytree(Tree T, Tree* NT)
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
int _stdcall depthtree(Tree T)
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
int _stdcall treelnode_num(Tree T)
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
int _stdcall treeleave_num(Tree T)
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
/*Treenode* return_node(Tree T, const int target_node)
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
			return_pro(T->right, target_node);
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
	return NULL;
}

void chang_mod(Tree* T)
{

}

*/

Tree _stdcall build_hf(int hf_data[],int len)
{
	int i = 0;
	int counter = 0;
	int tree_node_num = 0;
	Tree all[20];
	for (int i = 0; i < len*2; i++)
	{
		Tree temp = (Tree)malloc(sizeof(Treenode));
		all[i] = temp;
	}

	for (int i = 0; i < len; i++)
	{
		all[i]->data = hf_data[i];
		all[i]->left = NULL;
		all[i]->right = NULL;

	}

	tree_node_num = (2 * (len+1)) - 1;
	counter = len;
	
	for (int j = counter; j > 1; j--)
	{
		Bubbling_Sort(all, j);
		Treenode* new = (Treenode*)malloc(sizeof(Treenode));//����һ��
		new->left = all[0];
		new->right = all[1];
		new->data = all[0]->data + all[1]->data;
		ListDelete(all, 0,j+1);
		ListDelete(all, 0, j+1);
		all[j-2] = new;
	}
	return all[0];
}

void _stdcall Bubbling_Sort(Treenode* L[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < (len- i - 1); j++)
		{
			if (L[j + 1]->data <= L[j]->data)
			{
				Treenode* swap = L[j];
				L[j] = L[j + 1];
				L[j + 1] = swap;
			}
			else
			{
				continue;
			}
		}
	}
}

void _stdcall Insert_Sort(Treenode* L[],int len)
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
void _stdcall ListDelete(Treenode* L[], int index,int len)
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
}

void _stdcall test_hf(void)
{
	int a[] = { 1,2,3,4 };
	int counter = 0;
	Tree temp = build_hf(a, 4);
	PreOrderTraverse(temp);
	printf("temp.right.rigth��Ҷ�ӽڵ����%d\n", temp->right->right->data);
	char *return_= return_code_bynode(temp, temp->right->right);
	
}

int _stdcall is_parent(Treenode* top, Treenode* low)
{

	if (top->left==NULL&&top->right==NULL)
	{
		return 0;
	}
	if (top->left==low ||top->right==low)
	{
		return 1;
	}
	return is_parent(top->left, low)||is_parent(top->right ,low);
	
}
//�����õݹ��㷨��
int InOrderTraverse_hf(Tree T,Treenode* leave_node,char p[])
{
	static int flag = 1;
	static int counter = 0;
	if (T->left==NULL&&T->right==NULL) //��ʾ��Ŀ��ڵ�
	{
		if (T == leave_node)
		{
			return OK;
		}
	}
	else
	{
		InOrderTraverse_hf(T->left,leave_node,p);
		if (is_parent(T,leave_node)||T==leave_node)
		{
			if (T == leave_node)
			{
				return OK;
			}
			p[counter++] = '1';
		}
		InOrderTraverse_hf(T->right,leave_node,p);
		if (is_parent(T,leave_node)||T==leave_node)
		{
			if (T == leave_node)
			{
				return OK;
			}
			p[counter++] = '0';
		}
		
	}
	return OK;
}

char* return_code_bynode(Tree T, Treenode* leave_node)
{
	char leave_code[10];
	InOrderTraverse_hf(T, leave_node, leave_code);
	return leave_code;
}// ���ݽ��õĹ����������õ�Ҷ�ӽڵ�ı���