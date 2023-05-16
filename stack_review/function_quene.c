#include <stdio.h>
#include <stdlib.h>
#include "quene.h"

/*���в�����غ�������*/
int initQuene(SqQuene* Q)
{
	Q->data = (int*)malloc(sizeof(int) * Maxlength); //��������ռ�
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

/*��ͷ���ӣ����ӿ��Ƕӿ�*/
/*��β��ӣ���ӿ��Ƕ���*/

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

/*ȡ��ͷԪ��front*/

int GetHead(SqQuene Q)
{
	if (Q.front != Q.rear) //���в�Ϊ��
	{
		return Q.data[Q.front];
	}
	return ERROR;
}

/*���е���ʽ��ʾ��*/
/*β�����*/
/*ͨ������ָ��ͷ����front��������ָ�����*/
