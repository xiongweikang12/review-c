#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*	
	CreatSlist(void) //创造一个
	initList(&L) //初始化操作，建立一个空的线性表L
	DeotroyList(&L) //摧毁已存在的线性表L
	ClearList(&L) //将线性表清空
	ListInsert(&L,i,e) //在线性表L中第i个位置插入新元素e
	ListDelete(&L,i,&e) //删除线性表L中的第i个位置元素
	isempty(L) //若线性表为空，返回true，否则false
	Listlength(L) // 返回线性表的元素个数
	locateElem(L,e) //查询索引返回


	//注释：这些操作函数需要对顺序表修改，通过传入指针操作，
	而不需要的则对其顺序表的实参进行

*/



SqList* CreatSlist(void);
	//建立顺序表（给其动态分派一块内存）
SqList* CreatSlist(void){

	SqList* newsqlist = (SqList*)malloc(sizeof(SqList));
	return newsqlist;
}
//创造一个顺序表,return 指向Sqlist的pointer

int initList(SqList *L);
 //初始化对顺序表指针进行操作
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
  //对顺序表销毁（释放顺序表内存）
void DeotroyList(SqList* L)
{
	if (L)
	{
		free(L);
	}
}

int Listinsert(SqList* L, int index, int content);
//对e在i为位置上插入
//其定义时默认 顺序表中的data为int,总之其插入元素与data elemtype为同一种元素类型

int	Listinsert(SqList* L, int index, int content)
{	

	/*
		L：表示指针
		i:表示插入位置（索引）
		e:表示插入元素
	
	*/
	/*
		两种插入模式：
		插入到最后但是小于LIST_INIT_SIZE
		插入到数组中间或者最前方
	
	*/
	if (0 < index < LIST_INIT_SIZE-1)
	{
		if (index > L->length-1) {
			L->data[L->length] = content;
			L->length++;
		}//表示插入位置在长度后面
		else
		{
			for (int i = L->length-1; i >= index; i--)
			{	/*表示从最后到索引位置都往后移动一个位置*/
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
		} //插入位置超出边界
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
/*向顺序表添加内容*/

void inputsq(SqList* L)
{
	if (L->length == 0)
	{	
		int index = 0;
		int content = 0;
		while (1)
		{
			printf("输入:");
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
/*遍历访问顺序表*/
int visitsq(SqList L)
{	
	if (L.length == 0)
	{
		printf("顺序表没有内容无法遍历访问");
		return ERROR;
	}
	for (int i = 0; i < L.length; i++)
	{
		printf("索引为%d的内容：%d\n", i, L.data[i]);
	}
	return OK;
}

int Listlength(SqList L);
/*返回顺序表长度*/
int Listlength(SqList L)
{
	return L.length;
}

int ListDelete(SqList* L, int index);
/*删除index处的data*/

int ListDelete(SqList* L, int index)
{
	/*
	两种情况
	索引为最后
	索引不在最后
	*/
	if (index == L->length - 1)
	{
		L->length--;
	}
	else
	{	//从索引后一个进行覆盖，直到最后
		for (int i = index + 1; i < L->length; i++)
		{
			L->data[i - 1] = L->data[i];
		}
		L->length--;
	}
	return 0;
}

