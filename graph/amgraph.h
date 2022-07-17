/*
��ͼ��ʾ�ڽӾ���
��������ֱ�洢�������ڽӾ���
*/


//ARRAY ����

#define MVNUM 20
typedef char VertexType; //�������������Ϊ�ַ�����
typedef int arctype; //��ͼ�����ͱ�Ȩ

typedef struct am{
	VertexType ves[MVNUM]; //�����
	arctype arcs[MVNUM][MVNUM]; //�ڽӶ�ά�����
	int vexnum, arcnum; //
	int* visited; //���������¼����
}AMGraph ;



//�ڽӱ�Ĵ洢��ʽ 
typedef struct arcNode{
	int nodeindex; //�ڽ�Ԫ������
	arcNode * next; //ָ��
	int info; //�ͱ������Ϣ
}arcNode; //���

typedef struct VNode {
	VertexType data; //��������
	arcNode *fristarc; //ͷָ��
}VNode,AdjList[MVNUM];

/*���� adjList v; �൱��VNode v[MVNUM]*/

typedef struct {
	AdjList vertice; 
	int vexnum, arcnum; //��ʾ������Ŀ�ͻ���
	int *visited;
}ALGraph;


//ʮ������ ��������ͼ
typedef struct t_lnode {
	int tail; //β������
	int head; //ͷ������
	struct t_lnode  *hlink;  //��ʾͷ��ͬ�����ȣ�
	struct t_lnode  *tlink;   //��ʾβ����ͬ����ȣ�
}T_Lnode;

typedef struct {
	VertexType data; //��������
	T_Lnode *in; //��ʾ�뻡
	T_Lnode *out;  //��ʾ����
}T_topnode,T_toplist[MVNUM];

typedef struct {
	T_toplist  vertice;
	int vexnum, arcnum;

}ALGraph_ten; //ʮ�������ʾ��

//�ڽӶ��ر�
//Ϊ�����ظ�����������ͼ���Ķ�Ӧ�ߵĽ����Ϣ��
//ʹ�ö��ָ�������ⴴ��ʵ�������ɵĿռ��˷�

typedef struct m_Lnode{
	int head; //ͷ����
	int tail; //β����
	struct m_Lnode* headlink; //����ָ��
	struct m_Lnode* headlink_tong;//ͬΪ���ȵ��Ǳ�ʾͬ�ȵĹ�ϵ
	struct m_Lnode* taillink; //���ָ��
}m_Lnode; //�ڽӶ��ر���

typedef struct {
	VertexType data;
	m_Lnode* edgelink; //ͷָ��
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
//��ʾһ������


