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
	/*由于其对自定义结构体进行操作，而对于传入形参，只return int
	想通过不返回对应数据类型，而从函数内部操作改变内部，（需要通过指针类型）*/
}

int isempty(Sqstack S)
{
	if (S.top == S.base) //栈顶，栈底指向同一位置之间没有元素栈空
	{
		return TRUE; //表示栈空
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
		/*释放指针*/
		/*stacksize置为0*/
		/*指针置空*/
		free(S->base);
		S->stacksize = 0;
		S->top = S->base = NULL;
	}
	return OK;
}

/*入栈*/
int StackPush(Sqstack *S, int content)
{
	/*判断是否栈满,若满则出错（上溢出）*/
	/*元素压入栈*/
	/*栈顶指针加一*/
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

/*出栈*/
int Stackpop(Sqstack *S)
{
	/*判断是是否为栈空*/
	/*指针下移，出栈（return content) 指针不动*/
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

/*链式栈*/
//其操作方法就是链表中的头插法
//


