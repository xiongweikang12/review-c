/*ջ�Ĳ���������*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "quene.h"
#include "LInk_stack.h"

void main()
{
	Sqstack* Sp = (Sqstack*)malloc(sizeof(Sqstack));
	initStack(Sp); //��ʼ��
	StackPush(Sp, 3);
	printf("��ջ�ɹ�\n");
	if (Sp)
	{ 
		if (isempty(*Sp)) //ȡ��NULL��Sp������
		{
			printf("ջ��\n");
		}
		else
		{
			printf("�ǿ�\n");
		}
		printf("%d", Stackpop(Sp));
		if (isempty(*Sp))
		{
			printf("ջ��\n");
		}
		else
		{
			printf("�ǿ�\n");
		}
	}

	{
		SqQuene* Q = (SqQuene*)malloc(sizeof(SqQuene));
		int content = 0;
		int* e = &content;
		initQuene(Q);
		EeQuene(Q, 100);
		EeQuene(Q, 50);
		if (Q)
		{
			printf("%d\n", GetHead(*Q));
			DeQuene(Q, e);
			printf("%d\n", *e);
			DeQuene(Q, e);
			printf("%d\n", *e);
		}
	}


	{
		//��ջ��test����
		L_Lnode_Stack L1 = create_Lnode_stack();
		int temp_1 = 1;
		int* const temp = &temp_1;
		int get = 0;
		init_Lnode_stack(L1);
		get=Lnode_stack_push(L1, 1);
		get=Lnode_stack_push(L1, 2);
		get=Lnode_stack_push(L1, 3);
		get=Lnode_stack_push(L1, 4);
		get=Lnode_stack_pop(L1, temp);
		printf("%d\n",current_stack_length(L1)); // ����Ϊ3
		Destory_Link_stack(L1);
		printf("%d\n",current_stack_length(L1)); //����Ϊ0
	}
	
}