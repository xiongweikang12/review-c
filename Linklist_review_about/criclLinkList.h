/*ѭ������*/
//���һ������ָ����ָ��ͷ��㣬���������γ�һ����

typedef struct cLnode {
	int data;
	struct cLnode* next;
}cLnode,*cLinkList;

cLinkList CreatcLinkList(void);
cLinkList InitcLinkList(cLinkList cL);
cLinkList Bulid_cL(cLinkList cL_head);
int isEmpty(cLinkList cL_head);
int visitcL(cLinkList cL_head);
int LenghtcL(cLinkList cL_head);
int getelemcL(cLinkList cL_rear, cLinkList cL_head, int position);