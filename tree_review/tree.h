#define Tree_

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
	int tag; //����ģʽ
}Treenode, * Tree;

typedef struct two_node
{
	Treenode* frist_node;
	Treenode* second_node;
}Two_node;

int PreOrderTraverse(Tree T);
void creattree(Tree* T,int);
int InOrderTraverse(Tree T);
int postOrderTraverse(Tree T);
int copytree(Tree T, Tree* NT);
int depthtree(Tree T);
int treelnode_num(Tree T);
int treeleave_num(Tree T);
// Treenode* return_node(Tree T, const int target_node);
// Treenode* return_pro(Tree T, const Treenode* pro);
// void chang_mod(Tree* T);
void Bubbling_Sort(Treenode* L[], int len);
Tree build_hf(int *,int);
void Insert_Sort(Treenode* L[], int len);
void ListDelete(Treenode* L[], int index, int len);
void test_hf();
