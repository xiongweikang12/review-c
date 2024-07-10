#ifndef Tree_Child
#define Tree_Child
#define Maxsize 100

#define CHILD_TREE_API _declspec(dllexport)
#ifdef __cplusplus
extern "C"
{
#endif
	typedef struct cnode
	{
		int child_index; //节点索引
		struct cnode* next_child; //节点指针
	}tree_child_node;

	//表示孩子链表节点

	typedef struct cbox
	{
		char info; //节点信息
		tree_child_node* frist_child; //孩子指针
	}tree_child_box;

	//表示单个节点

	typedef struct c_tree_one {
		int num; //表示树的节点个数
		tree_child_box c_tree[Maxsize];
	}tree_child;

	CHILD_TREE_API int _stdcall init_tree_child(tree_child*);
	CHILD_TREE_API int _stdcall creat_tree__child(tree_child*); //创建box_node
	CHILD_TREE_API int _stdcall build_child_tree(tree_child*); //建立表示孩纸
	CHILD_TREE_API int _stdcall return_child(tree_child*, const char, char*);//返回某个节点的孩子数，保存在某个数组中
	CHILD_TREE_API tree_child_box _stdcall return_parent(tree_child*, const char);//返回双亲

	#ifdef __cplusplus

}
#endif // 


#endif // !Tree_Child
