#include "LinkList.h"
#include "criclLinkList.h"
#include <stdio.h>
#include <stdlib.h>

cLinkList CreatcLinkList(void)
{
	cLinkList cL_head = (cLinkList*)malloc(sizeof(cLinkList));
	return cL_head;
}

cLinkList InitcLinkList(cLinkList cL)
{	
	cLinkList cL_rear = cL; //加上尾指针
	if (cL)
	{
		cL->next = cL;
		cL_rear->next = cL;
	}
	return cL_rear;
}

cLinkList Bulid_cL(cLinkList cL_head)
{
	cLinkList cL_rear = cL_head;
	int content = 0;
	while (True)
	{
		printf("please input:");
		scanf_s("%d", &content);
		if (content == -1)
		{
			break;
		}
		else
		{
			cLnode *cLnew = (cLnode*)malloc(sizeof(cLnode));
			if (cLnew)
			{
				cLnew->data = content;
				cLnew->next = cL_head;
				cL_rear->next = cLnew;
				cL_rear = cLnew;
				continue;

			}
		}
	}
	return cL_rear; //返回尾指针
}

int isEmpty(cLinkList cL_head)
{
	if (cL_head)
	{
		if (cL_head->next == cL_head)
		{
			return ERROR; //表示为空表
		}
		else
		{
			return OK;
		}
	}
	return ERROR;
}

int visitcL(cLinkList cL_head)
{	
	if (isEmpty(cL_head))
	{
		int connter = 1;
		cLinkList p = cL_head->next; //从第一个结点起遍历
		while (p->next!=cL_head)
		{
			printf("第%d:%d->", connter, p->data);
			p = p->next;
			connter++;
		}
		return OK;
	}
	printf("it is empty");
	return ERROR;
}

int LenghtcL(cLinkList cL_head)
{
	if (isEmpty(cL_head))
	{
		
		int connter = 1;
		cLinkList p = cL_head->next;//从第一个结点起遍历
		while (p->next != cL_head)
		{
			printf("第%d:%d->", connter, p->data);
			p = p->next;
			connter++;
		}
		return connter;
	}
	else
	{
		return 0;
	}
}

int getelemcL(cLinkList cL_rear,cLinkList cL_head, int position) //实际返回类型(elemtype)自定（这里用int)
{
	int len = LenghtcL(cL_head);
	if (isEmpty(cL_head) || position>len)
	{
		return ERROR;
	}
	else
	{
		
		if (len== position)
		{
			return cL_rear->data;
		}
		else if (len == 1)
		{
			return cL_rear->next->data;
		}
		else
		{	
			int connter = 1;
			cLinkList p = cL_head->next; //从第一个结点起遍历
			while (p->next != cL_head)
			{
				if (connter == position)
				{
					// printf("第%d:%d->", connter, p->data);
					return p->data;
				}
				p = p->next;
				connter++;
				continue;
			}
		}	
	}
}