#ifndef Link_stack
#define Link_stack

//������ջ,��ͷ���ģ�ֻ������ͷ�����в���
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
//��ʾջ������ָ��


//�ṹ�嶨��

L_Lnode_Stack create_Lnode_stack(void); //����һ����ͷ���(��nextָ��ָ����ջԪ��)��ָ��
void init_Lnode_stack(L_Lnode_Stack inin_stack_L);//��ʼ��
int Lnode_stack_push(L_Lnode_Stack inin_stack_L, int data_push);//��ջ;
int Lnode_stack_pop(L_Lnode_Stack inin_stack_L, int *const getpop );//��ջ
int Lnode_stack_get(L_Lnode_Stack inin_stack_L, int* const gettop);//��ȡջ��Ԫ��
int current_stack_length(L_Lnode_Stack inin_stack_L); //��ȡջ����,ͬʱ�жϿ�
void Destory_Link_stack(L_Lnode_Stack inin_stack_L); //����ջ





#endif // !Link_stack
