#ifndef Tree_
#define Tree_




/*对定义二叉树的结构类型*/
/*二叉树的顺序存储：按满二叉树的结点层次编号，依次存放二叉树的数据元素*/
//优点：实现简单用数组实现既可以
//缺点：对于一些二叉树其存储有点浪费空间
//适合于存满二叉树和完全二叉树

//链式对于树整体是个用结点递归的定义的

#define OK 1
#define ERROR 0
#define TREE_API _declspec(dllexport)
#ifdef __cplusplus
extern "C"
{
#endif
	typedef struct treenode {
		int data;//数据域
		struct treenode* left; //左孩子
		struct treenode* right; //右孩子
		int tag; //树的模式
	}Treenode, * Tree;

	/*
	typedef struct two_node
	{
		Treenode* frist_node;
		Treenode* second_node;
	}Two_node;
	*/

	TREE_API int _stdcall PreOrderTraverse(Tree T);
	TREE_API void _stdcall creattree(Tree* T, int);
	TREE_API int _stdcall InOrderTraverse(Tree T);
	TREE_API int  _stdcall postOrderTraverse(Tree T);
	TREE_API int _stdcall copytree(Tree T, Tree* NT);
	TREE_API int _stdcall depthtree(Tree T);
	TREE_API int _stdcall treelnode_num(Tree T);
	TREE_API int _stdcall treeleave_num(Tree T);
	// Treenode* return_node(Tree T, const int target_node);
	// Treenode* return_pro(Tree T, const Treenode* pro);
	// void chang_mod(Tree* T);
	TREE_API void _stdcall Bubbling_Sort(Treenode* L[], int len);
	TREE_API Tree _stdcall build_hf(int*, int);
	TREE_API void _stdcall Insert_Sort(Treenode* L[], int len);
	TREE_API void _stdcall ListDelete(Treenode* L[], int index, int len);
	TREE_API char* _stdcall return_code_bynode(Tree, Treenode*);
	TREE_API int _stdcall PreOrderTraverse_hf(Tree T, int tag, Treenode*);
	TREE_API void _stdcall test_hf();

#ifdef __cplusplus
}
#endif
#endif // !Tree_



