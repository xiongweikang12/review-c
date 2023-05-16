#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -1
#define UNDERFLOW -1
#define STACKSIZE_MAX 20
#define OK 1
#define TRUE 1
#define FALSE 0
#pragma once




typedef struct stack {

	int *top; //栈顶指针,用于操作数组的
	int *base; //栈底指针
	int stacksize; //栈大小

}Sqstack;

// /*typedef struct stack {  栈的另一种定义方式
//	int *base; //定义数组
//	int front;
//	int rear;
// }Sqstack_1;
// */

int initStack(Sqstack* S);
int isempty(Sqstack S);
int StackLength(Sqstack S);
int ClearStack(Sqstack* S);
int DeotroyStack(Sqstack* S);
int StackPush(Sqstack* S, int content);
int Stackpop(Sqstack* S);