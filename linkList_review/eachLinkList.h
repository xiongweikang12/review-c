/*˫������*/

typedef struct eachLnode {

	int data; //elemtype var;
	struct eachLnode *pri; //ǰ��
	struct eachLnode *next; //���
}eachLnode,*each_LinkList;

each_LinkList Creat_eachLinklist(void);
void init_each_linkList(each_LinkList eL);
void build_eachlinkList(each_LinkList eL);
int each_linkList_length(each_LinkList eL);
int insert_eachNode(const each_LinkList eL, eachLnode* data_node, int location); //λ�����
void visit_eachLinkList(const each_LinkList eL,int is_head);
eachLnode* serach_eachnode(int location, const each_LinkList eL); //Ϊ��Ѱֵ
eachLnode* Delete_eachnode(int location, const each_LinkList eL);  //λ��ɾ��
void insert_eachNode_bypointer(const each_LinkList eL,eachLnode* insert_Lnode,eachLnode* op_pointer);
int Delete_eachnode_bypointer(const each_LinkList eL, int num, eachLnode* delete_location);
//����ָ����룬Ѱַ��ɾ��
