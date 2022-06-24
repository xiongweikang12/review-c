#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*	
	CreatSlist(void) //����һ��
	initList(&L) //��ʼ������������һ���յ����Ա�L
	DeotroyList(&L) //�ݻ��Ѵ��ڵ����Ա�L
	ClearList(&L) //�����Ա����
	ListInsert(&L,i,e) //�����Ա�L�е�i��λ�ò�����Ԫ��e
	ListDelete(&L,i,&e) //ɾ�����Ա�L�еĵ�i��λ��Ԫ��
	isempty(L) //�����Ա�Ϊ�գ�����true������false
	Listlength(L) // �������Ա��Ԫ�ظ���
	locateElem(L,e) //��ѯ��������


	//ע�ͣ���Щ����������Ҫ��˳����޸ģ�ͨ������ָ�������
	������Ҫ�������˳����ʵ�ν���

*/



SqList* CreatSlist(void);
	//����˳������䶯̬����һ���ڴ棩
SqList* CreatSlist(void){

	SqList* newsqlist = (SqList*)malloc(sizeof(SqList));
	return newsqlist;
}
//����һ��˳���,return ָ��Sqlist��pointer

int initList(SqList *L);
 //��ʼ����˳���ָ����в���
int initList(SqList *L)
{	
	L->length = 0;
	L->data = (int*)malloc(sizeof(int) * LIST_INIT_SIZE);
	if (!L->data)
	{
		exit(Overflow);
	}
	return OK;
}

void DeotroyList(SqList* L);
  //��˳������٣��ͷ�˳����ڴ棩
void DeotroyList(SqList* L)
{
	if (L)
	{
		free(L);
	}
}

int Listinsert(SqList* L, int index, int content);
//��e��iΪλ���ϲ���
//�䶨��ʱĬ�� ˳����е�dataΪint,��֮�����Ԫ����data elemtypeΪͬһ��Ԫ������

int	Listinsert(SqList* L, int index, int content)
{	

	/*
		L����ʾָ��
		i:��ʾ����λ�ã�������
		e:��ʾ����Ԫ��
	
	*/
	/*
		���ֲ���ģʽ��
		���뵽�����С��LIST_INIT_SIZE
		���뵽�����м������ǰ��
	
	*/
	if (0 < index < LIST_INIT_SIZE-1)
	{
		if (index > L->length-1) {
			L->data[L->length] = content;
			L->length++;
		}//��ʾ����λ���ڳ��Ⱥ���
		else
		{
			for (int i = L->length-1; i >= index; i--)
			{	/*��ʾ���������λ�ö������ƶ�һ��λ��*/
				L->data[i + 1] = L->data[i];
			}
			L->data[index] = content;
			L->length++;
		}
	}
	else
	{
		if (index > LIST_INIT_SIZE-1)
		{
			return Overflow;
		} //����λ�ó����߽�
		else
		{
			for (int j = L->length-1; j >= 0; j--)
			{
				L->data[j + 1] = L->data[j];
			}
			L->data[0] = content;
			L->length++;
		}
	}
	return OK;
}

void inputsq(SqList* L);
/*��˳����������*/

void inputsq(SqList* L)
{
	if (L->length == 0)
	{	
		int index = 0;
		int content = 0;
		while (1)
		{
			printf("����:");
			scanf_s("%d",&content);
			if (content == -1)
			{
				break;
			}
			Listinsert(L, index, content);
			index++;
		}
	}
}

int visitsq(SqList L);
/*��������˳���*/
int visitsq(SqList L)
{	
	if (L.length == 0)
	{
		printf("˳���û�������޷���������");
		return ERROR;
	}
	for (int i = 0; i < L.length; i++)
	{
		printf("����Ϊ%d�����ݣ�%d\n", i, L.data[i]);
	}
	return OK;
}

int Listlength(SqList L);
/*����˳�����*/
int Listlength(SqList L)
{
	return L.length;
}

int ListDelete(SqList* L, int index);
/*ɾ��index����data*/

int ListDelete(SqList* L, int index)
{
	/*
	�������
	����Ϊ���
	�����������
	*/
	if (index == L->length - 1)
	{
		L->length--;
	}
	else
	{	//��������һ�����и��ǣ�ֱ�����
		for (int i = index + 1; i < L->length; i++)
		{
			L->data[i - 1] = L->data[i];
		}
		L->length--;
	}
	return 0;
}

