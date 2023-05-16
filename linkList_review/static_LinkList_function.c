#include "static_Linklist_function.h"
#include <stdlib.h>

static_Linklist* create_static_Linklist()
{
	static_Linklist* new_container = (static_Linklist*)malloc(sizeof(static_Linklist) * MAXSIZE_STATIC_LINKLIST);
	return new_container;
}

int init_static_Linklist(static_Linklist* s1)
{
	int counter = 0;
	while (counter++<MAXSIZE_STATIC_LINKLIST)
	{
		s1[counter].data = 0;
		s1[counter].next = UNUSED_LINKLIST_NEXT;
	}
	return 1;
}

void build_static_Linklist(static_Linklist* s1)
{
	//静态建表的建立
	int data_1 = -1;
	int counter = 0; //表示从
	int next_up = 0;
	while (1)
	{
		printf("please insert data:");
		scanf_s("%d", &data_1);
		if (data_1 == -1) { s1[counter].next = END_STATIC_LINKLIST; break; }//表示为尾巴结点
		else {
			if (counter == 0)
			{
				//表示为头结点
				s1[0].next = ++counter;
				next_up = 0;
			}
			else
			{
				//s1[s1[next_up].next].next = ++counter;
				int now_index = s1[next_up].next;
				s1[now_index].data = data_1;
				s1[now_index].next = ++counter;
				next_up = now_index;
			}
			continue;
		}
	}
	printf("alright");
}

void iter_visit_static_Linklist(static_Linklist* s1)
{
	int head_index = 0;
	int local_index = 0;
	while (s1[local_index].next != END_STATIC_LINKLIST)
	{
		if (head_index == 0) { local_index = s1[local_index].next; }
		else{
			printf("->%d", s1[local_index].data);
			local_index = s1[local_index].next;	}
		head_index = 1;
	}
	printf("\n alright");
	//有问题明天改正。
}