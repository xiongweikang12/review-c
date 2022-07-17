/*
用图表示邻接矩阵
两个数组分别存储顶点表和邻接矩阵
*/


//ARRAY 数组

#define MVNUM 20
typedef char VertexType; //顶点的数据类型为字符类型
typedef int arctype; //网图整数型边权

typedef struct am{
	VertexType ves[MVNUM]; //顶点表
	arctype arcs[MVNUM][MVNUM]; //邻接二维矩阵表
	int vexnum, arcnum; //
	int* visited; //辅助数组记录访问
}AMGraph ;



//邻接表的存储方式 
typedef struct arcNode{
	int nodeindex; //邻接元素索引
	arcNode * next; //指针
	int info; //和边相关信息
}arcNode; //结点

typedef struct VNode {
	VertexType data; //顶点数据
	arcNode *fristarc; //头指针
}VNode,AdjList[MVNUM];

/*其中 adjList v; 相当于VNode v[MVNUM]*/

typedef struct {
	AdjList vertice; 
	int vexnum, arcnum; //表示顶点数目和弧数
	int *visited;
}ALGraph;


//十字链表 用于有向图
typedef struct t_lnode {
	int tail; //尾部索引
	int head; //头部索引
	struct t_lnode  *hlink;  //表示头相同（出度）
	struct t_lnode  *tlink;   //表示尾部相同（入度）
}T_Lnode;

typedef struct {
	VertexType data; //顶点数据
	T_Lnode *in; //表示入弧
	T_Lnode *out;  //表示出弧
}T_topnode,T_toplist[MVNUM];

typedef struct {
	T_toplist  vertice;
	int vexnum, arcnum;

}ALGraph_ten; //十字链表表示法

//邻接多重表
//为避免重复（对于无向图）的对应边的结点信息。
//使用多个指针来避免创造实体结点而造成的空间浪费

typedef struct m_Lnode{
	int head; //头索引
	int tail; //尾索引
	struct m_Lnode* headlink; //出度指针
	struct m_Lnode* headlink_tong;//同为出度但是表示同等的关系
	struct m_Lnode* taillink; //入度指针
}m_Lnode; //邻接多重表结点

typedef struct {
	VertexType data;
	m_Lnode* edgelink; //头指针
}morenode,morelist[MVNUM];

typedef struct {
	morelist  vertice;
	int vexnum, arcnum;
}MoreGraph ;


#define True 1
#define ERROR 0

typedef struct {
	AdjList ad;
	int F;
	int R;
}QadjList;
//表示一个队列


