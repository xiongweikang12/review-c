#define Tree_Child
#define Maxsize 100

typedef struct cnode
{
	int child_index; //�ڵ�����
	struct cnode *next_child; //�ڵ�ָ��
}tree_child_node;

//��ʾ��������ڵ�

typedef struct cbox
{
	char info; //�ڵ���Ϣ
	tree_child_node *frist_child; //����ָ��
}tree_child_box;

//��ʾ�����ڵ�

typedef struct c_tree_one{
	int num; //��ʾ���Ľڵ����
	tree_child_box* c_tree;
}tree_child;

int init_tree_child(tree_child*);
int creat_tree__child(tree_child*); //����box_node
int build_child_tree(tree_child*); //������ʾ��ֽ
int return_child(tree_child*, char, char*);//����ĳ���ڵ�ĺ�������������ĳ��������
