#include <stdio.h>
#include <stdlib.h>
#include "stack.h"




int initStack(Sqstack *S)
{

	S->base = (int*)malloc(sizeof(int) * STACKSIZE_MAX);
	if (!S->base)
	{
		exit(OVERFLOW);
	}
	S->top = S->base;
	S->stacksize = STACKSIZE_MAX;
	return OK;
	/*��������Զ���ṹ����в����������ڴ����βΣ�ֻreturn int
	��ͨ�������ض�Ӧ�������ͣ����Ӻ����ڲ������ı��ڲ�������Ҫͨ��ָ�����ͣ�*/
}

int isempty(Sqstack S)
{
	if (S.top == S.base) //ջ����ջ��ָ��ͬһλ��֮��û��Ԫ��ջ��
	{
		return TRUE; //��ʾջ��
	}
	else
	{
		return FALSE;
	}
}

int StackLength(Sqstack S)
{
	return S.top - S.base;
}

int ClearStack(Sqstack *S)
{
	if (S->base)
	{
		S->top = S->base;
	}
	return OK;
}

int DeotroyStack(Sqstack *S)
{
	if (S->base)
	{
		/*�ͷ�ָ��*/
		/*stacksize��Ϊ0*/
		/*ָ���ÿ�*/
		free(S->base);
		S->stacksize = 0;
		S->top = S->base = NULL;
	}
	return OK;
}

/*��ջ*/
int StackPush(Sqstack *S, int content)
{
	/*�ж��Ƿ�ջ��,����������������*/
	/*Ԫ��ѹ��ջ*/
	/*ջ��ָ���һ*/
	if (S->top - S->base == S->stacksize)
	{
		return OVERFLOW;
	}
	else
	{
		*(S->top) = content;
		S->top++;
		return OK;
	}
}

/*��ջ*/
int Stackpop(Sqstack *S)
{
	/*�ж����Ƿ�Ϊջ��*/
	/*ָ�����ƣ���ջ��return content) ָ�벻��*/
	if (S->top == S->base)
	{
		return UNDERFLOW;
	}
	else
	{
		S->top--;
		return *(S->top);
	}
}

/*��ʽջ*/
//������������������е�ͷ�巨
//


