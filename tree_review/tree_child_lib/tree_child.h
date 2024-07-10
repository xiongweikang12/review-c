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
		int child_index; //�ڵ�����
		struct cnode* next_child; //�ڵ�ָ��
	}tree_child_node;

	//��ʾ��������ڵ�

	typedef struct cbox
	{
		char info; //�ڵ���Ϣ
		tree_child_node* frist_child; //����ָ��
	}tree_child_box;

	//��ʾ�����ڵ�

	typedef struct c_tree_one {
		int num; //��ʾ���Ľڵ����
		tree_child_box c_tree[Maxsize];
	}tree_child;

	CHILD_TREE_API int _stdcall init_tree_child(tree_child*);
	CHILD_TREE_API int _stdcall creat_tree__child(tree_child*); //����box_node
	CHILD_TREE_API int _stdcall build_child_tree(tree_child*); //������ʾ��ֽ
	CHILD_TREE_API int _stdcall return_child(tree_child*, const char, char*);//����ĳ���ڵ�ĺ�������������ĳ��������
	CHILD_TREE_API tree_child_box _stdcall return_parent(tree_child*, const char);//����˫��

	#ifdef __cplusplus

}
#endif // 


#endif // !Tree_Child
