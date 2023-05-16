#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "criclLinkList.h"
#include "eachLinkList.h"
#include "static_Linklist_function.h"


void main(void)
{
	/*LinkList L = CreatLinkList();
	// LinkList* LL = L;
	if (initLinklist(L))
	{
		printf("right\n");
	}
	BuildLinkList_head(L);
	VisitLinkList(L);

	/*头插法*/

	/*
	LinkList LL = CreatLinkList();
	if (initLinklist(LL))
	{
		printf("right\n");
	}
	BuildLinkList_rear(LL);
	VisitLinkList(LL);
	LinkList L2 = unionTwoLinkList(L, LL);
	VisitLinkList(L2);
	/*尾插法*/
	/*printf("在3处插入8\t");
	InsertLinkList(LL, 8, 3);
	VisitLinkList(LL);
	printf("删除位置3的元素\t");
	DeleteleLinkList(LL,3);
	VisitLinkList(LL);
	if (Isempty(LL))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	// printf("%d\n", LenghtLinkList(LL));
	printf("%d\n", LengthLinkListc(LL));

	{	printf("循环链表部分运行");
		cLinkList cL_head = CreatcLinkList();
		InitcLinkList(cL_head);
		cLinkList cL_rear = Bulid_cL(cL_head);
		printf("循环链表遍历");
		visitcL(cL_head);
		printf("\n");
		printf("%d", getelemcL(cL_rear, cL_head, 1));
	}
	*/

	{
		each_LinkList e1 = Creat_eachLinklist();
		init_each_linkList(e1);
		build_eachlinkList(e1); // 1 2 3 4
		visit_eachLinkList(e1, 0);
		visit_eachLinkList(serach_eachnode(2, e1), 1); // 2 3 4
		// eachLnode *temp= Delete_eachnode(2, e1); //删除成功 //1 3 4
		each_LinkList e2 = Creat_eachLinklist();
		init_each_linkList(e2);
		build_eachlinkList(e2); // 1 2 3 4
		visit_eachLinkList(e2, 0);
		eachLnode* temp1 = Delete_eachnode(2, e2); //删除成功 //1 3 4
		insert_eachNode_bypointer(e1, temp1,serach_eachnode(2, e1));
		//1 1 3 4 2 3 4
		visit_eachLinkList(e1, 0);
		Delete_eachnode_bypointer(e1, 2, serach_eachnode(1, e1));
		//表示从第一开始删除，删除2个
		//3 4 2 3 4
		visit_eachLinkList(e1, 0);
	}
	
	{
		static_Linklist* s1 = create_static_Linklist();
		init_static_Linklist(s1);
		build_static_Linklist(s1);// 1 2 3 4
		iter_visit_static_Linklist(s1); // 2 3 4 第一个结点不保留信息
	}
	
}