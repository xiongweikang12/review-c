#define OK 1
#define ERROR 0
#define Overflow -1
#define True 1
#define False 0



/*������//ָ����*/
typedef struct Lnode {

	int data; //elemtype ������������һ��ֻ��һ�������Զ��
	struct Lnode  *next; //ָ����

}Lnode,*LinkList;

/* LinkList L ��������L*/
/*LNode *p ������ָ�루���ڲ�����㣩*/

//��ʼ����
// �����½����ͷ��㣬��ͷָ��ָ��ͷ���
// ͷ���ָ�����ÿ�

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

//˳���ϲ�
LinkList unionTwoLinkList(LinkList L1, LinkList L2);


