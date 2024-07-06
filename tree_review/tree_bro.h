#define Tree_bro

typedef struct Tree_bro_node
{
	char data;
	struct Tree_bro_node* first_child; //表示第一个孩子
	struct Tree_bro_node* nextsibling; //表示自己的兄弟
}Tree_bro_Node, * Tree_bro_point;

