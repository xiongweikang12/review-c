
//线索二叉树的数据类型定义
//以及相关预定义字符
 
/*
ltag=0 lchild指向该结点地左孩子
ltag=1 lchild指向该结点地前驱
rtag=0 rchild指向该结点地右孩纸
rtag=1 rchild 指向该结点地后继
*/
//设置结点标志域用以区分，孩子结点还是顺序结点
typedef struct thrnode {
	int data;
	int ltag, rtag;
	struct thrnode *lchild ,*rchild;
}thrnode,*thrtree;



