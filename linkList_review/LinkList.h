#define OK 1
#define ERROR 0
#define Overflow -1
#define True 1
#define False 0



/*数据域//指针域*/
typedef struct Lnode {

	int data; //elemtype 数据域，数据域不一定只有一个，可以多个
	struct Lnode  *next; //指针域

}Lnode,*LinkList;

/* LinkList L 定义链表L*/
/*LNode *p 定义结点指针（用于操作结点）*/

//初始化，
// 生成新结点作头结点，用头指针指向头结点
// 头结点指针域置空

LinkList CreatLinkList(void);
int initLinklist(LinkList L);
int Isempty(LinkList L);
void DeotoryLinkList(LinkList L);
void ClearLinkList(LinkList L);
int LenghtLinkList(LinkList L);
int LengthLinkListc(LinkList L);
int getelemLinkList(LinkList L, int index);
int InsertLinkList(LinkList L, int content, int index);
int DeleteleLinkList(LinkList L, int index);
void BuildLinkList_head(LinkList L);
void BuildLinkList_rear(LinkList L);
void VisitLinkList(LinkList L);

//顺序表合并
LinkList unionTwoLinkList(LinkList L1, LinkList L2);


