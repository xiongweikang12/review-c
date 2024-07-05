#include <stdio.h>
#include "array_sort.h"

//��������Insert_Sort

void Insert_Sort(Sqlist* L)
{
	//��˳�����������в�������
	for (int i = 2; i < L->length; i++)//�ӵڶ���λ�ÿ�ʼ
	{
		if (L->r[i].key <= L->r[i-1].key)
		{	
			//���߱�ǰ��С,�ؼ�����Ϊ�Ƚ�����
			L->r[0] = L->r[i];
			int j = i - 1;
			while (L->r[j].key > L->r[0].key)//
			{
				L->r[j + 1] = L->r[j];
				//����ƶ�
				j--;
			}
			//С��ʱ�˳�,�����뵽С��λ�ú�ĵط�
			L->r[j + 1] = L->r[0];
		}
	}
}

void BanInsert_Sort(Sqlist* L)
{
	for (int i = 2; i < L->length; i++)
	{
		if (L->r[i].key <= L->r[i - 1].key)//С��ǰ��
		{
			L->r[0] = L->r[i]; //�������������ݵ�Ԫ
			int low = 1;
			int high = i - 1;
			while (low<=high) //low>high��������
			{
				int mid = (low + high) / 2;
				if (L->r[mid].key > L->r[0].key)
				{
					//����ֵС���һ�룬����λ���ų���һ��
					high = mid - 1;
				}
				else
				{
					//����ֵ����ǰһ�룬����λ���ų�ǰһ��
					low = mid + 1;
				}
				
			}
			for (int j = i - 1; j >=high+1; --j)
			{
				//�õ�����λ�ã�ѭ���Ⱥ��ƶ�
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
			right--; //ָ���ƶ�����
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
	//char B/b ��ʾ�Ǵ����,S/s��ʾ��С����
	//�ڵ�Ϊ2I+1
	//�ڵ�Ϊ2I+2
	//�Ϲ��˽���������
	//����һ������ָ��
	return build_head(L);
}

void heap_sort(Sqlist* push_L, Sqlist* pull_L)
{
	//push_L����ѣ�pull_L����󴫳���






}//������
