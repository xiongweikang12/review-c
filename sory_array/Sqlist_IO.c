#include  <stdio.h>
#include "array_sort.h"

void Output_key(Sqlist L)
{	
	printf("\n");
	for (int i = 0; i < L.length; i++)
	{
		printf("%d\t",L.r[i].key);
	}
}

void Input_key(Sqlist *L)
{
	int i = 0;
	do
	{
		int intput_key =-1;
		printf("\n输入顺序表关键值：");
		scanf_s("%d", &intput_key);
		if (intput_key ==0)
		{
			break;
		}
		else
		{
			L->r[i++].key = intput_key;
		}
	} while (1);

	L->length = i;
}

