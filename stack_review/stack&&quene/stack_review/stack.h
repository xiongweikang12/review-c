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

	int *top; //ջ��ָ��,���ڲ��������
	int *base; //ջ��ָ��
	int stacksize; //ջ��С

}Sqstack;

// /*typedef struct stack {  ջ����һ�ֶ��巽ʽ
//	int *base; //��������
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