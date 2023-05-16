#ifndef Link_stack
#define Link_stack

//创建链栈,带头结点的，只允许在头部进行操作
typedef struct Lnode_stack
{
	int data;
	struct Lnode_stack* next;
	// int length;
}Lnode_Stack;

typedef struct Lnode_stack_head_
{
	int max_capacity;
	int lenght;
	Lnode_Stack* next;
	// int length;
}Lnode_stack_head;

typedef Lnode_stack_head* L_Lnode_Stack; 
//表示栈顶操作指针


//结构体定义

L_Lnode_Stack create_Lnode_stack(void); //创建一个带头结点(其next指针指向链栈元素)的指针
void init_Lnode_stack(L_Lnode_Stack inin_stack_L);//初始化
int Lnode_stack_push(L_Lnode_Stack inin_stack_L, int data_push);//入栈;
int Lnode_stack_pop(L_Lnode_Stack inin_stack_L, int *const getpop );//出栈
int Lnode_stack_get(L_Lnode_Stack inin_stack_L, int* const gettop);//获取栈顶元素
int current_stack_length(L_Lnode_Stack inin_stack_L); //获取栈长度,同时判断空
void Destory_Link_stack(L_Lnode_Stack inin_stack_L); //销毁栈





#endif // !Link_stack
