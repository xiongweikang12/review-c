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

	/*ͷ�巨*/

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
	/*β�巨*/
	/*printf("��3������8\t");
	InsertLinkList(LL, 8, 3);
	VisitLinkList(LL);
	printf("ɾ��λ��3��Ԫ��\t");
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

	{	printf("ѭ������������");
		cLinkList cL_head = CreatcLinkList();
		InitcLinkList(cL_head);
		cLinkList cL_rear = Bulid_cL(cL_head);
		printf("ѭ���������");
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
		// eachLnode *temp= Delete_eachnode(2, e1); //ɾ���ɹ� //1 3 4
		each_LinkList e2 = Creat_eachLinklist();
		init_each_linkList(e2);
		build_eachlinkList(e2); // 1 2 3 4
		visit_eachLinkList(e2, 0);
		eachLnode* temp1 = Delete_eachnode(2, e2); //ɾ���ɹ� //1 3 4
		insert_eachNode_bypointer(e1, temp1,serach_eachnode(2, e1));
		//1 1 3 4 2 3 4
		visit_eachLinkList(e1, 0);
		Delete_eachnode_bypointer(e1, 2, serach_eachnode(1, e1));
		//��ʾ�ӵ�һ��ʼɾ����ɾ��2��
		//3 4 2 3 4
		visit_eachLinkList(e1, 0);
	}
	
	{
		static_Linklist* s1 = create_static_Linklist();
		init_static_Linklist(s1);
		build_static_Linklist(s1);// 1 2 3 4
		iter_visit_static_Linklist(s1); // 2 3 4 ��һ����㲻������Ϣ
	}
	
}