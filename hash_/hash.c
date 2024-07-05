#include <stdio.h>
#include "hash.h"

int SeachHT(HashTable ha, int p, KeyType key)
{	//在哈希表中查找
	//遵循着某种映射的
	//通过关键字传入，返回地址
	//其存储也是遵循这样的规则的
	int i = 0;
	int adress = key % p;
	while (ha[adress].key!=NULLKEY && ha[adress].key!=key)
	{
		i++; //表示冲突，key已存在，或NULLKEY
		adress = (adress + 1) % p;//线性探测到下一个可行的地址
	}
	if (ha[adress].key == key)
	{
		return adress; //查找成功
	}
	else
	{
		return -1;//返回失败
	}
}

int DeleteHT(HashTable ha, int p, KeyType key)
{	//删除，通过Search key返回 adress
	//无查找，返回-1
	//将待删除key,通过地址访问修改key为DELKEY
	int adress = SeachHT(ha, p, key);
	if (adress != -1)
	{
		ha[adress].key = DELKEY;//标记
		return 1;
	}
	else
	{
		return 0;//删除失败
	}
}

void InsertHT(HashTable ha, int p, KeyType key)
{
	int adress = key % p;
	int i = 0;
	//插入在key为NULLKEY 和 DELKEY处
	if (ha[adress].key == NULLKEY || ha[adress].key == DELKEY)
	{
		ha[adress].key = key;
		ha[adress].count = 1;
	}
	else //ha[adress]已存在key的情况，进行线性探索
	{
		i = 1;
		do
		{
			adress = (adress + 1) % p;
			i++;

		} while (ha[adress].key!=NULLKEY &&ha[adress].key!=DELKEY);
		//要满足两个都成立就退出
		ha[adress].key = key;
		ha[adress].count = i;
	}
}

void creatHT(HashTable ha, int p, KeyType key[],int n)
{ //创建时传入关键值数组
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}//初始化
	for (i = 0; i < n; i++)
	{
		InsertHT(ha, p, key[i]);
	}
}

void DisplayHT(HashTable ha, int n)
{
	printf("哈希表地址 :\t");
	for (int i = 0; i < n; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	printf("哈希表关键字 :\t");
	for (int i = 0; i < n; i++)
	{
		if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
		{
			printf("   ");
		}
		else
		{
			printf("%3d", ha[i].key);
		}
	}
	printf("\n");
	printf(" 搜索次数 :\t ");
	for (int i = 0; i < n; i++)
	{
		if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
		{
			printf("   ");
		}
		else
		{
			printf("%3d", ha[i].count);
		}
	}
	printf("\n");
	show_ASL(ha, n);
}

void show_ASL(HashTable ha, int n)
{
	int  i;
	double sum_road = 0;
	double i_key = 0;
	for (i = 0; i < n; i++)
	{
		if (ha[i].key != NULLKEY && ha[i].key != DELKEY)
		{
			i_key++;
			sum_road += ha[i].count;
		}
		else
		{
			continue;
		}
	}
	printf("\n散列表此次查找的ASL为 : % .2f", (sum_road / i_key));

}