
//���Ĵ洢�ṹ
//1.˫�ױ�ʾ�� 
/*
1.����ṹ���������Ľ��
2.ÿ��������������
�����򣺴�ű�����Ϣ
˫���򣺱�ʾ���˫�׽���������е�λ�ã�������

�ص㣺˫�����ף��Һ����ѡ�

*/


typedef struct PTnode {
	int data; //������
	int parent; //˫��������
}PTnode;
//���ṹ

#define MAX_TREE_SIZE 20

typedef struct {
	PTnode * node;
	int r, n; //�����λ�ã�������
}PTree;

int Creatpr_tree(PTree* PT);
PTnode search_ptnode(int content, PTree* PT);