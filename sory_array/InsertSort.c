#include <stdio.h>
#include "array_sort.h"

//插入排序，Insert_Sort

void Insert_Sort(Sqlist* L)
{
	//对顺序表操作，进行插入排序
	for (int i = 2; i < L->length; i++)//从第二个位置开始
	{
		if (L->r[i].key <= L->r[i-1].key)
		{	
			//后者比前者小,关键字作为比较依据
			L->r[0] = L->r[i];
			int j = i - 1;
			while (L->r[j].key > L->r[0].key)//
			{
				L->r[j + 1] = L->r[j];
				//向后移动
				j--;
			}
			//小于时退出,并插入到小于位置后的地方
			L->r[j + 1] = L->r[0];
		}
	}
}

void BanInsert_Sort(Sqlist* L)
{
	for (int i = 2; i < L->length; i++)
	{
		if (L->r[i].key <= L->r[i - 1].key)//小于前者
		{
			L->r[0] = L->r[i]; //保存待插入的数据单元
			int low = 1;
			int high = i - 1;
			while (low<=high) //low>high结束条件
			{
				int mid = (low + high) / 2;
				if (L->r[mid].key > L->r[0].key)
				{
					//插入值小与后一半，插入位置排除后一半
					high = mid - 1;
				}
				else
				{
					//插入值打于前一半，插入位置排除前一半
					low = mid + 1;
				}
				
			}
			for (int j = i - 1; j >=high+1; --j)
			{
				//得到插入位置，循环先后移动
				L->r[j + 1] = L->r[j];
			}
			L->r[high + 1] = L->r[0];
		}
	}
}

void Bubbling_Sort(Sqlist* L)
{
	for (int i = 0; i < L->length-1; i++)
	{
		for (int j = 0; j < (L->length - i-1); j++)
		{
			if (L->r[j + 1].key <= L->r[j].key)
			{
				redtype swap = L->r[j];
				L->r[j] = L->r[j + 1];
				L->r[j + 1] = swap;
			}
			else
			{
				continue;
			}
		}
	}
}

void Choice_Sort(Sqlist* L)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < L->length; i++)
	{
		int min = L->r[i].key;
		for (j = i; j < L->length; j++)
		{
			if (L->r[j].key <= min)
			{
				min = L->r[j].key;
				k = j;
			}
			else
			{
				continue;
			}
		}
		if (k != i)
		{
			redtype swap = L->r[i];
			L->r[i] = L->r[k];
			L->r[k] = swap;
		}
	}
}

int partion(Sqlist* L, int left, int right)
{
	redtype priv = L->r[left];
	while (left<right)
	{
		while (left < right && L->r[right].key > priv.key)
		{
			right--; //指针移动过程
		}
		L->r[left] = L->r[right];
		while (left < right && (L->r[left].key < priv.key || L->r[left].key == priv.key))
		{
			left++;
		}
		L->r[right] = L->r[left];
	}
	L->r[left] = priv;
	return left;
}

void quick_Sort(Sqlist* L, int left, int right)
{
	if (left<right)
	{
		int pos = partion(L, left, right);
		quick_Sort(L, left, pos - 1);
		quick_Sort(L, pos + 1, right);
	}
}

int get_top(int now_node)
{
	if (now_node%2==0 &&now_node!=0)
	{
		return (now_node / 2) - 1;
	}
	if(now_node % 2 != 0 && now_node != 0)
	{
		return now_node / 2;
	}
	if (now_node==0)
	{
		return -1;
	}
}

int heap_big(Sqlist* L)
{
	for (int i = 0; i < L->length; i++)
	{
		int fun_counter = i;
		while (1)
		{
			if (i > 0 && L->r[fun_counter].key > L->r[get_top(fun_counter)].key)
			{
				redtype temp = L->r[get_top(fun_counter)];
				L->r[get_top(fun_counter)] = L->r[fun_counter];
				L->r[fun_counter] = temp;
			}
			else
			{
				break;
			}
			if (get_top(fun_counter) == -1)
			{
				break;
			}
			else
			{
				fun_counter = get_top(fun_counter);
				continue;
			}
		}
	}
	return 1;
}

int heap_small(Sqlist* L)
{
	for (int i = 0; i < L->length; i++)
	{
		int fun_counter = i;
		while (1)
		{
			if (i > 0 && L->r[fun_counter].key < L->r[get_top(fun_counter)].key)
			{
				redtype temp = L->r[get_top(fun_counter)];
				L->r[get_top(fun_counter)] = L->r[fun_counter];
				L->r[fun_counter] = temp;
			}
			else
			{
				break;
			}
			if (get_top(fun_counter) == -1)
			{
				break;
			}
			else
			{
				fun_counter = get_top(fun_counter);
				continue;
			}
		}
	}
	return 1;
}

int heap_sort_check(Sqlist* L, int(*build_head)(Sqlist*))
{
	//char B/b 表示是大根堆,S/s表示是小根堆
	//节点为2I+1
	//节点为2I+2
	//上过滤建立堆排序
	//传入一个函数指针
	return build_head(L);
}

void heap_sort(Sqlist* push_L, Sqlist* pull_L)
{
	//push_L传入堆，pull_L排序后传出堆






}//堆排序
