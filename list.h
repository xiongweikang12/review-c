#define LIST_INIT_SIZE 100 //���Ա���ռ�ĳ�ʼ������
#define OK 1
#define ERROR 0
#define Overflow -2


/*���������������Ա�Ķ���*/
/*
	ADT List {
		���ݶ��� D={ai|ai����Elemset,��i=1��2....n>=0��}
		���ݹ�ϵ R={<ai-1,ai|ai-1,ai����D,(i=2,3,.....n)}
		����������
			initList(&L)��
			Destroy(&L);
			ListInsert(&L,i,e);
			ListDelete(&L,i,&e);
			...�ȵ�
		}ADT List
*/

/*
	���Ա��ɱ䣨ɾ����
	���鳤�Ȳ��ɶ�̬���� -����һ��������ʾ˳���ĳ�������
*/

typedef struct {
	int* data;
	//���� int ��ʾΪ����Ԫ�أ���������򵥵�int��ʾ
	//��������Զ����һ������
	/*
	��ͼ����Ϣ
	typedef struct {
	char no[20]
	char name[50]
	float price;
	}Book;

	Book data[LIST_INIT_SIZE]; 
	*/
	int length;				//���鳤��
}SqList; //˳��洢

SqList* CreatSlist(void);
void DeotroyList(SqList* L);
int initList(SqList* L);
int Listinsert(SqList* L, int index, int content);
void inputsq(SqList* L);
int visitsq(SqList L);
int Listlength(SqList L);
int ListDelete(SqList* L, int index);







