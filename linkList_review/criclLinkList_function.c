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
	cLinkList cL_rear = cL; //����βָ��
	if(cL)
	{
		cL->next = cL;
		cL_rear->next = cL;
		//��ʾָ������
	}
	return cL_rear;
	//�Ǵ�ͷָ���
}

cLinkList Bulid_cL(cLinkList cL_head)
{
	
	// cL_head = (cLinkList)malloc(sizeof(cLnode));
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
				cLnew->next = cL_head; //
				cL_rear->next = cLnew;
				cL_rear = cLnew;
				continue;
			}
		}
	}
	return cL_rear; //����βָ��
}

int isEmpty(cLinkList cL_head)
{
	if (cL_head)
	{
		if (cL_head->next == cL_head)
		{
			return ERROR; //��ʾΪ�ձ�
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
		cLinkList p = cL_head->next; //�ӵ�һ����������
		while (p!=cL_head) //�ж��Ƿ������ȫ
		{
			printf("%d->", p->data);
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
		cLinkList p = cL_head->next;//�ӵ�һ����������
		while (p->next!= cL_head)
		{
			// printf("%d->", p->data);
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

int getelemcL(cLinkList cL_rear,cLinkList cL_head, int position) //ʵ�ʷ�������(elemtype)�Զ���������int)
{
	int len = LenghtcL(cL_head);
	if (!isEmpty(cL_head) || position>len) //Ϊ�ձ�򳬳���Χ
	{
		return ERROR;
	}
	else
	{
		
		if (len== position) //��ʾ��ȡѭ������β����Ԫ��
		{
			return cL_rear->data;
		}
		else if (position== 1) //��ʾ��ȡѭ������ͷ��
		{
			return cL_rear->next->next->data;  //����ͷ���
		}
		else
		{	
			int connter = 1;
			cLinkList p = cL_head->next; //�ӵ�һ����������
			while (p!= cL_head)
			{
				if (connter == position)
				{
					// printf("��%d:%d->", connter, p->data);
					return p->data;
				}
				p = p->next;
				connter++;
				continue;
			}
		}	
	}
}