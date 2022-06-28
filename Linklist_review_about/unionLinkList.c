#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*有序表的合并--用链表实现*/
//注意要求单个链表是有序的
LinkList unionTwoLinkList(LinkList L1, LinkList L2)
{
	if (Isempty(L1))
	{
		//表示L1为空表
		return L2;
	}
	else if (Isempty(L2))
	{
		//表示L2为空表
		return L1;
	}
	else
	{
		//默认用L1的头头结点
		Lnode *p1 = L1->next; //L1的操作操作指针，指向首元结点
		Lnode *p2 = L2->next; //L2的操作指针，指向首元结点
		Lnode *pc = L1;
		while (p1&&p2)
		{
			if (p1->data <= p2->data) //从小到大排序
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
		pc->next = p1 ? p1 : p2; //表示接上
		return L1;
	}
}