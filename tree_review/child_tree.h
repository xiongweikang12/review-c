 //���ӱ�ʾ��

typedef struct CTnode {
	//���庢ֽ�ڵ�,����ڵ㣬��ֽ����
	int child; //�洢��ֽ�ڵ������
	struct CTnode * next;
}*childptr;

typedef struct {
	int data; //��ʾ���ڵ�����
	childptr firstchild; //��ֽ����
}CTBox;

typedef struct {
	CTBox *node;
	int n, r; //�ڵ����������ڵ�
}CTree;

#define NO_child NULL