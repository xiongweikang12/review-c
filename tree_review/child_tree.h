 //孩子表示法

typedef struct CTnode {
	//定义孩纸节点,链表节点，孩纸链表
	int child; //存储孩纸节点的索引
	struct CTnode * next;
}*childptr;

typedef struct {
	int data; //表示树节点内容
	childptr firstchild; //孩纸链表
}CTBox;

typedef struct {
	CTBox *node;
	int n, r; //节点数量，根节点
}CTree;

#define NO_child NULL