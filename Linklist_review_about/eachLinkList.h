/*双向链表*/

typedef struct eachLnode {

	int data; //elemtype var;
	struct eachLnode *pri; //前驱
	struct eachLnode *next; //后继
}eachLnode,*each_LinkList;

