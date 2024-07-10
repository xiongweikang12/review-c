#ifndef Tree_
#define Tree_




/*�Զ���������Ľṹ����*/
/*��������˳��洢�������������Ľ���α�ţ����δ�Ŷ�����������Ԫ��*/
//�ŵ㣺ʵ�ּ�������ʵ�ּȿ���
//ȱ�㣺����һЩ��������洢�е��˷ѿռ�
//�ʺ��ڴ�������������ȫ������

//��ʽ�����������Ǹ��ý��ݹ�Ķ����

#define OK 1
#define ERROR 0
#define TREE_API _declspec(dllexport)
#ifdef __cplusplus
extern "C"
{
#endif
	typedef struct treenode {
		int data;//������
		struct treenode* left; //����
		struct treenode* right; //�Һ���
		int tag; //����ģʽ
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



