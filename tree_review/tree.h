/*�Զ���������Ľṹ����*/
/*��������˳��洢�������������Ľ���α�ţ����δ�Ŷ�����������Ԫ��*/
//�ŵ㣺ʵ�ּ�������ʵ�ּȿ���
//ȱ�㣺����һЩ��������洢�е��˷ѿռ�
//�ʺ��ڴ�������������ȫ������

//��ʽ�����������Ǹ��ý��ݹ�Ķ����

#define OK 1
#define ERROR 0



typedef struct treenode {
	int data;//������
	struct treenode* left; //����
	struct treenode* right; //�Һ���
}Treenode,*Tree;

int PreOrderTraverse(Tree T);
void creattree(Tree* T);






