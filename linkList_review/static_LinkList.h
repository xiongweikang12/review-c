#pragma once
#ifndef STATIC_LINKLIST
#define STATIC_LINKLIST

#define MAXSIZE_STATIC_LINKLIST 20
#define UNUSED_LINKLIST_NEXT  -2
#define END_STATIC_LINKLIST -1

typedef struct L1{
	int data;
	int next; //以下标索引的方式表示链式关系
}static_Linklist;


#endif // !STATIC_LINKLIST

