#include <stdio.h>
#include "LinkList.h"
#include <stdlib.h>


LinkList CreatLinkList(void)
{
	LinkList newLinkList = (LinkList*)malloc(sizeof(LinkList));
	return newLinkList;
}
/*创造返回一个链表头指针*/

int initLinklist(LinkList L)
{
	if (L)
	{
		(L)->next = NULL;
	}
	return OK;
}

/*初始化，头指针指向指针域置空的头结点*/

int Isempty(LinkList L)
{	
	LinkList p = L;
	if (p)
	{
		if (p->next == NULL)
		{
			return OK; //表示为空表
		}
		else
		{
			return ERROR; //表示不为空表
		}
	}
	return Overflow; //表示头指针错误
}

/*判断是否为空表*/

void DeotoryLinkList(LinkList L)
{
	/*单链表销毁*/
	/*从头指针开始，依次释放所有结点*/
	Lnode *p;
	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}
}

/*摧毁单链表，释放所有结点（包括头结点）*/

void ClearLinkList(LinkList L)
{
	/*清空单链表*/
	/*从头指针开始，依次释放所有结点（保留头结点，并且指针域置空）*/
	Lnode* p = L->next;
	Lnode* q;
	
	while (p)
	{
		q = p->next;
		free(p);
		p = q; //相当于 p=p->next
	}
	L->next = NULL; //头结点指针域置空
}
/*清空链表*/

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
/*递归写法，链表长度*/

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

/*链表长度迭代写法*/

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
/* 获取链表中的index处的元素*/

int InsertLinkList(LinkList L ,int content,int index)
{
	/*在第i个结点前插入*/
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
		/*生成一个新的结点*/
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
		//插入位置非法
	}
	
}
/*在index处插入content新结点*/

int DeleteleLinkList(LinkList L, int index)
{

	/*删除第i个结点*/
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

/*删除第i个结点*/

void BuildLinkList_head(LinkList L)
{
	/*头插法建立链表*/
	//从一个空表开始，带头结点的空链表
	//生成新结点，将读入数据存放到新结点的数据中
	//从最后一个结点开始，依次将各结点插入到最前端（最头部是最后插入的）
	int content = 0;
	Lnode *copter = L;//指向头结点
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

/*头插法建立链表*/

void BuildLinkList_rear(LinkList L)
{
	/*尾插法建立链表*/
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

/*尾插法*/

void VisitLinkList(LinkList L)
{
	/*遍历访问链表*/
	LinkList p = L->next;
	int conuter = 1;
	while (p)
	{
		printf("第%d个:%d->", conuter, p->data);
		conuter++;
		p = p->next;
	}
	printf("\n");
}