#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "criclLinkList.h"


void main(void)
{
	LinkList L = CreatLinkList();
	// LinkList* LL = L;
	if (initLinklist(L))
	{
		printf("right\n");
	}
	BuildLinkList_head(L);
	VisitLinkList(L);

	/*ͷ�巨*/
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
	InsertLinkList(LL, 8, 3);
	VisitLinkList(LL);
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

	{
		cLinkList cL_head = CreatcLinkList();
		InitcLinkList(cL_head);
		cLinkList cL_rear = Bulid_cL(cL_head);
		visitcL(cL_head);
		printf("%d", getelemcL(cL_rear, cL_head, 1));
	}
	
}