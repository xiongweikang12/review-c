#define LIST_INIT_SIZE 100 //线性表储存空间的初始分配量
#define OK 1
#define ERROR 0
#define Overflow -2


/*抽象数据类型线性表的定义*/
/*
	ADT List {
		数据对象 D={ai|ai属于Elemset,（i=1，2....n>=0）}
		数据关系 R={<ai-1,ai|ai-1,ai属于D,(i=2,3,.....n)}
		基本操作：
			initList(&L)；
			Destroy(&L);
			ListInsert(&L,i,e);
			ListDelete(&L,i,&e);
			...等等
		}ADT List
*/

/*
	线性表长可变（删除）
	数组长度不可动态定义 -》用一个变量表示顺序表的长度属性
*/

typedef struct {
	int* data;
	//数组 int 表示为数据元素，这里用最简单的int表示
	//其可以是自定义的一个类型
	/*
	如图书信息
	typedef struct {
	char no[20]
	char name[50]
	float price;
	}Book;

	Book data[LIST_INIT_SIZE]; 
	*/
	int length;				//数组长度
}SqList; //顺序存储

SqList* CreatSlist(void);
void DeotroyList(SqList* L);
int initList(SqList* L);
int Listinsert(SqList* L, int index, int content);
void inputsq(SqList* L);
int visitsq(SqList L);
int Listlength(SqList L);
int ListDelete(SqList* L, int index);







