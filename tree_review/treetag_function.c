//������������غ���
//
#include "treetag.h"
#include <stdio.h>

//����������

static thrtree pre = NULL;
//ȫ�ֱ��������ڴ洢���
//��ʼ�Һ��ӷǿ�


void Inthreading(thrtree T)
{	
	if (T)
	{
		Inthreading(T->lchild);
		if (!(T->lchild)) //��ʾΪ������ǰ��
		{
			T->lchild = pre; //ǰ��
			T->ltag = 1;
		}
		else
		{
			T->ltag = 0;
		}
		if (!(pre->rchild))  //�ݹ鷵��,pre��T��
		{
			pre->ltag = 1;
			pre->rchild = T; //���
		}
		else
		{
			pre->rchild = 0;
			pre = T; //ָ����󣬵ȴ��ݹ鷵��
		}
		Inthreading(T->rchild);
	}

}


void Inodertravse_tr(thrtree T)
{
	thrtree p = T->lchild; //ָ��ͷ�����Һ��Ӻ��
	while (p!=T) //��ʾΪ�������
	{
		while (p->ltag==0) //��ʾ�ǿ�
		{
			p = p->lchild;
			printf("\n�������� ��%d", p->data);
		}
		while (p->rtag==1 &&p!=T)
		{
			p = p->rchild; //��ʾ�Һ��Ӻ��
			printf("\n�������� :%d", p->data);
		}
		//ת�����Ҳ�����и���ʼ����������
		p = p->rchild; //ת���Һ��� 
	}
}