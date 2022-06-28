#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*�����ĺϲ�--������ʵ��*/
//ע��Ҫ�󵥸������������
LinkList unionTwoLinkList(LinkList L1, LinkList L2)
{
	if (Isempty(L1))
	{
		//��ʾL1Ϊ�ձ�
		return L2;
	}
	else if (Isempty(L2))
	{
		//��ʾL2Ϊ�ձ�
		return L1;
	}
	else
	{
		//Ĭ����L1��ͷͷ���
		Lnode *p1 = L1->next; //L1�Ĳ�������ָ�룬ָ����Ԫ���
		Lnode *p2 = L2->next; //L2�Ĳ���ָ�룬ָ����Ԫ���
		Lnode *pc = L1;
		while (p1&&p2)
		{
			if (p1->data <= p2->data) //��С��������
			{
				pc->next = p1; 
				pc = p1;
				p1 = p1->next;
			}
			else
			{
				pc->next = p2;
				pc = p2;
				p2 = p2->next;
			}
		}
		pc->next = p1 ? p1 : p2; //��ʾ����
		return L1;
	}
}