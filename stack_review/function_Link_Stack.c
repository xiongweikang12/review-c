#include "LInk_stack.h"
#include <stdlib.h>
#include <stdio.h>

L_Lnode_Stack create_Lnode_stack(void)
{
	L_Lnode_Stack created_stack_head = (Lnode_stack_head*)malloc(sizeof(Lnode_stack_head));
	return created_stack_head;
}

void init_Lnode_stack(L_Lnode_Stack inin_stack_L)
{
	//初始化链式栈，头结点data域保存length
	inin_stack_L->lenght = 0;
	inin_stack_L->max_capacity = 20;
	inin_stack_L->next = NULL;
}

int Lnode_stack_push(L_Lnode_Stack inin_stack_L, int data_push)
{
	if (inin_stack_L->lenght == inin_stack_L->max_capacity) { return 0; }
	else
	{
		Lnode_Stack* push_Lnode = (Lnode_Stack*)malloc(sizeof(Lnode_Stack));
		push_Lnode->data = data_push;
		push_Lnode->next = inin_stack_L->next;
		inin_stack_L->next = push_Lnode;
		++(inin_stack_L->lenght);
		return 1;
	}
}

int Lnode_stack_pop(L_Lnode_Stack inin_stack_L , int  *const getpop)
{
	// if (inin_stack_L->next == NULL || inin_stack_L->lenght==0) { return 0; }
	if (inin_stack_L->next == NULL || current_stack_length(inin_stack_L)==0) { return 0; }

	else
	{
		*getpop = inin_stack_L->next->data;
		Lnode_Stack* free_pointer = inin_stack_L->next;
		inin_stack_L->next = inin_stack_L->next->next;
		free_pointer->next = NULL;
		free(free_pointer);//释放结点
		--(inin_stack_L->lenght);
		return 1;
	}
}

int Lnode_stack_get(L_Lnode_Stack inin_stack_L, int* const gettop)
{
	//if (inin_stack_L->next == NULL || inin_stack_L->lenght == 0) { return 0; }
	if (inin_stack_L->next == NULL || current_stack_length(inin_stack_L)) { return 0; }

	else 
	{
		*gettop = inin_stack_L->next->data;
		return 1;
	}
}

int current_stack_length(L_Lnode_Stack inin_stack_L)
{
	return inin_stack_L->next == NULL ? 0 : inin_stack_L->lenght;
	//返回非空链栈长度,同时也可以作为判断是否为空
}

void Destory_Link_stack(L_Lnode_Stack inin_stack_L)
{
	if (current_stack_length(inin_stack_L)==0) { //连头结点都给你释放了 }
	}
	else
	{
		int temp_2 = 1;
		int* const temp = &temp_2;
		while (current_stack_length(inin_stack_L))  //传入实参
		{
			Lnode_stack_pop(inin_stack_L, temp);
		}
	}
}




