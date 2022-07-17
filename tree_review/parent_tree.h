
//树的存储结构
//1.双亲表示法 
/*
1.定义结构数组存放树的结点
2.每个结点包含两个域
数据域：存放本身信息
双亲域：表示结点双亲结点在数组中的位置（索引）

特点：双亲容易，找孩子难。

*/


typedef struct PTnode {
	int data; //数据域
	int parent; //双亲索引域
}PTnode;
//结点结构

#define MAX_TREE_SIZE 20

typedef struct {
	PTnode * node;
	int r, n; //根结点位置，结点个数
}PTree;

int Creatpr_tree(PTree* PT);
PTnode search_ptnode(int content, PTree* PT);