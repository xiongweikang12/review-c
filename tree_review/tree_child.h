#define Tree_Child
#define Maxsize 100

typedef struct cnode
{
	int child_index; //节点索引
	struct cnode *next_child; //节点指针
}tree_child_node;

//表示孩子链表节点

typedef struct cbox
{
	char info; //节点信息
	tree_child_node *frist_child; //孩子指针
}tree_child_box;

//表示单个节点

typedef struct c_tree_one{
	int num; //表示树的节点个数
	tree_child_box* c_tree;
}tree_child;

int init_tree_child(tree_child*);
int creat_tree__child(tree_child*); //创建box_node
int build_child_tree(tree_child*); //建立表示孩纸
int return_child(tree_child*, char, char*);//返回某个节点的孩子数，保存在某个数组中
