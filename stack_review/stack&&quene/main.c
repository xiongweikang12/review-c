/*ջ�Ĳ���������*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "quene.h"

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
	
}