#include <stdio.h>
#include "hash_link.h"
#include <stdlib.h>


//散列表的链地址法表示，相关函数定义

void intiHT(Hash_link HL, int n)
{
	for (int i = 0; i < n; i++)
	{
		HL[i].key_Link = NULL;
	}
	//初始化将所有结点指向NULL；
}

int InsertHL(Hash_link HL, int p, Keytype key)
{
	int adress = key % p;
	if (HL[adress].key_Link == NULL)
	{
		KeyNode *new = (KeyNode*)malloc(sizeof(KeyNode));
		//创建新结点
		new->keynext = NULL;
		new->key = key;
		HL[adress].key_Link = new;
		return INSERT_OK;
	}
	else
	{	
		Key_link pp = HL[adress].key_Link;
		//指向头结点
		while (pp->keynext)
		{
			if (pp->key == key)
			{
				//到尾部结点的路上，遍历比较，判断是否key存在
				//作为插入，添加新结点的依据
				printf("key:\t[ %d ]:\t %d 已存在，插入失败", adress, key);
				return INSERT_FAIL;
			}
			pp = pp->keynext;
		}
		if (pp->key == key)
		{
			//由于是尾插法，最后指针是指向尾巴结点
			//由于退出循环，所以要在外部判断尾巴结点
			printf("key:\t[ %d ]:\t %d 已存在，插入失败",adress,key);
			return INSERT_FAIL;
		}
		else
		{
			KeyNode* newp = (KeyNode*)malloc(sizeof(KeyNode));
			newp->key = key;
			newp->keynext = pp->keynext;
			pp->keynext = newp;
			//创建新节点，尾插法
			return INSERT_OK;

		}
	}
}

int SearchHL(Hash_link HL, int p, Keytype key)
{
	int adress = key % p;
	if (HL[adress].key_Link == NULL)
	{
		return NO_FIND_KEY;
	}
	else
	{
		Key_link pp = HL[adress].key_Link->keynext;
		while (pp)
		{	//遍历链表，查找，返回索引;
			if (pp->key == key)
			{
				return adress;
			}
			pp = pp->keynext;
		}
		return NO_FIND_KEY;
	}
}

void DeleteHL(Hash_link HL, int p, Keytype key)
{	
	int adress = SearchHL(HL, p, key);
	//通过查找，判断是否存在，来执行是否删除
	if ( adress!= NO_FIND_KEY)
	{
		Key_link pp = HL[adress].key_Link;
		while (pp->keynext)
		{
			if (pp->keynext->key == key) 
			{	//如果后继的key为关键值key
				//当前后继指向后继的后继
				//跳过待删除结点
				//free释放内存
				Key_link qq = pp->keynext;
				pp->keynext = pp->keynext->keynext;
				free(qq);
			}
			//链表删除
			pp = pp->keynext;
		}
		
	}
	else
	{
		printf("寻找不到，无法删除");
	}

}

void CreatHL(Hash_link HL, int p, Keytype key[])
{	
	int get_insert = 0;
	for (int i = 0; key[i] != END_INPUT_NUM; i++)
	{
		get_insert = InsertHL(HL, p, key[i]);
		//循环插入，创建哈希表
	}
}

void DisplayHL(Hash_link HL, int l)
{	
	//展示链地址法
	
	printf("\n");
	for (int i = 0; i < l; i++)
	{
		if (HL[i].key_Link == NULL)
		{
			printf("[%d]:^\t",i);
			printf("\n");
			continue;
		}
		else
		{
			//创建一个指针
			Key_link p = HL[i].key_Link;
			printf("[%d] : \t", i);
			while (p)
			{
				printf("%d -> ", p->key);
				p = p->keynext;
			}
			printf("\n");
		}
	}
}

