#include <stdio.h>
#include <stdlib.h>
#include "quene.h"

/*队列操作相关函数定义*/
int initQuene(SqQuene* Q)
{
	Q->data = (int*)malloc(sizeof(int) * Maxlength); //分配数组空间
	if (!(Q->data))
	{
		exit(OVERFLOW);
	}
	Q->front = Q->rear = 0;
	return OK;
}

int Quenelength(SqQuene Q)
{
	return((Q.rear - Q.front + Maxlength) % Maxlength);
}

int DeQuene(SqQuene* Q,int *e)
{	
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % Maxlength;
	return OK;
}

/*对头出队，出队考虑队空*/
/*队尾入队，入队考虑队满*/

int EeQuene(SqQuene *Q ,int content)
{
	if (((Q->rear + 1) % Maxlength) == Q->rear)
	{
		return ERROR;
	}
	Q->data[Q->rear] = content;
	Q->rear = ((Q->rear + 1) % Maxlength);
	return OK;
}

/*取队头元素front*/

int GetHead(SqQuene Q)
{
	if (Q.front != Q.rear) //队列不为空
	{
		return Q.data[Q.front];
	}
	return ERROR;
}

/*队列的链式表示法*/
/*尾插入队*/
/*通过类似指向头结点的front操作出队指针出队*/
