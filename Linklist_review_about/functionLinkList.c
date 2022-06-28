#include <stdio.h>
#include "LinkList.h"
#include <stdlib.h>


LinkList CreatLinkList(void)
{
	LinkList newLinkList = (LinkList*)malloc(sizeof(LinkList));
	return newLinkList;
}
/*���췵��һ������ͷָ��*/

int initLinklist(LinkList L)
{
	if (L)
	{
		(L)->next = NULL;
	}
	return OK;
}

/*��ʼ����ͷָ��ָ��ָ�����ÿյ�ͷ���*/

int Isempty(LinkList L)
{	
	LinkList p = L;
	if (p)
	{
		if (p->next == NULL)
		{
			return OK; //��ʾΪ�ձ�
		}
		else
		{
			return ERROR; //��ʾ��Ϊ�ձ�
		}
	}
	return Overflow; //��ʾͷָ�����
}

/*�ж��Ƿ�Ϊ�ձ�*/

void DeotoryLinkList(LinkList L)
{
	/*����������*/
	/*��ͷָ�뿪ʼ�������ͷ����н��*/
	Lnode *p;
	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}
}

/*�ݻٵ������ͷ����н�㣨����ͷ��㣩*/

void ClearLinkList(LinkList L)
{
	/*��յ�����*/
	/*��ͷָ�뿪ʼ�������ͷ����н�㣨����ͷ��㣬����ָ�����ÿգ�*/
	Lnode* p = L->next;
	Lnode* q;
	
	while (p)
	{
		q = p->next;
		free(p);
		p = q; //�൱�� p=p->next
	}
	L->next = NULL; //ͷ���ָ�����ÿ�
}
/*�������*/

int LenghtLinkList(LinkList L)
{
	Lnode *q = L->next;
	if (q == NULL)
	{
		return 1;
	}
	else
	{
		return LenghtLinkList(q->next)+1;
	}
}
/*�ݹ�д����������*/

int LengthLinkListc(LinkList L)
{
	Lnode *p = L->next;
	int sumlength = 0;
	while (p)
	{
		sumlength++;
		p = p->next;
	}
	return sumlength;
}

/*�����ȵ���д��*/

int getelemLinkList(LinkList L, int index)
{
	Lnode* p = L->next;
	int i = 1;

	while (p&&i<index)
	{
		i++;
		p = p->next;
	}
	if (p)
	{
		return p->data;
	}
	else
	{
		return ERROR;
	}
}
/* ��ȡ�����е�index����Ԫ��*/

int InsertLinkList(LinkList L ,int content,int index)
{
	/*�ڵ�i�����ǰ����*/
	Lnode* p = L;
	int i = 0;
	while (p && i<index-1)
	{
		i++;
		p = p->next;
	}
	if (p)
	{
		Lnode* insertLnode = (Lnode*)malloc(sizeof(Lnode));
		/*����һ���µĽ��*/
		if (insertLnode)
		{
			insertLnode->data = content;
			insertLnode->next = p->next;
			p->next = insertLnode;
			return OK;
		}
	}
	else
	{
		return ERROR;
		//����λ�÷Ƿ�
	}
	
}
/*��index������content�½��*/

int DeleteleLinkList(LinkList L, int index)
{

	/*ɾ����i�����*/
	Lnode* p = L;
	int i = 0;
	while (p && i<index-1)
	{
		i++;
		p = p->next;
	}
	if (p)
	{	
		Lnode* q = p->next;
		p->next = q->next;
		free(q);
		return OK;
	}
	else
	{
		return ERROR;
	}
}

/*ɾ����i�����*/

void BuildLinkList_head(LinkList L)
{
	/*ͷ�巨��������*/
	//��һ���ձ�ʼ����ͷ���Ŀ�����
	//�����½�㣬���������ݴ�ŵ��½���������
	//�����һ����㿪ʼ�����ν��������뵽��ǰ�ˣ���ͷ����������ģ�
	int content = 0;
	Lnode *copter = L;//ָ��ͷ���
	while (True)
	{
		printf("please input content:");
		scanf_s("%d", &content);
		if (content == -1)
		{
			break;
		}
		else
		{	
			Lnode *newponiter_Lnode = (Lnode*)malloc(sizeof(Lnode));
			if (newponiter_Lnode)
			{
				newponiter_Lnode->data = content;
				newponiter_Lnode->next = copter->next;
				copter->next = newponiter_Lnode;
				//copter = newponiter_Lnode;
			}
			continue;
		}
	}
}

/*ͷ�巨��������*/

void BuildLinkList_rear(LinkList L)
{
	/*β�巨��������*/
	int content = 0;
	Lnode* copter = L;
	while (True)
	{
		printf("please input content:");
		scanf_s("%d", &content);
		if (content == -1)
		{
			break;
		}
		else
		{
			Lnode *newponiter_Lnode = (Lnode*)malloc(sizeof(Lnode));
			if (newponiter_Lnode)
			{
				newponiter_Lnode->data = content;
				newponiter_Lnode->next = copter->next;
				copter->next = newponiter_Lnode;
				copter = newponiter_Lnode;

			}

			continue;
		}
	}
}

/*β�巨*/

void VisitLinkList(LinkList L)
{
	/*������������*/
	LinkList p = L->next;
	int conuter = 1;
	while (p)
	{
		printf("��%d��:%d->", conuter, p->data);
		conuter++;
		p = p->next;
	}
	printf("\n");
}