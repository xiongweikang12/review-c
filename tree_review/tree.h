#define Tree_

/*对定义二叉树的结构类型*/
/*二叉树的顺序存储：按满二叉树的结点层次编号，依次存放二叉树的数据元素*/
//优点：实现简单用数组实现既可以
//缺点：对于一些二叉树其存储有点浪费空间
//适合于存满二叉树和完全二叉树

//链式对于树整体是个用结点递归的定义的

#define OK 1
#define ERROR 0



typedef struct treenode {
	int data;//数据域
	struct treenode* left; //左孩子
	struct treenode* right; //右孩子
	int tag; //树的模式
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
