#define Tree_bro

typedef struct Tree_bro_node
{
	char data;
	struct Tree_bro_node* first_child; //��ʾ��һ������
	struct Tree_bro_node* nextsibling; //��ʾ�Լ����ֵ�
}Tree_bro_Node, * Tree_bro_point;

