#include <stdio.h>

//key对应了一条链表，
//冲突同义的储存在链表中，
//避免了探针探索重复查找的过程

#define NO_FIND_KEY -1 //没有找到key

#define END_INPUT_NUM -1 //插入创建哈希表的结束标志

#define INSERT_FAIL 0 //插入失败，存在key

#define INSERT_OK 1 //插入成功

//散列表的链地址法表示，相关函数声明，结构体定义

typedef int Keytype;

typedef int value;

typedef struct keynode {
	Keytype key;
	struct keynode* keynext;
}KeyNode ,*Key_link;
//链表指针，与链表结点的定义

typedef struct hash_keylink {
	value data;
	Key_link key_Link;
}Hash_link[20];
//一个带链表指针的哈希表

void intiHT(Hash_link, int);

int InsertHL(Hash_link, int, Keytype);

int SearchHL(Hash_link, int, Keytype);

void DeleteHL(Hash_link, int, Keytype);

void CreatHL(Hash_link, int, Keytype[]);

void DisplayHL(Hash_link, int);

