
//�������������������Ͷ���
//�Լ����Ԥ�����ַ�
 
/*
ltag=0 lchildָ��ý�������
ltag=1 lchildָ��ý���ǰ��
rtag=0 rchildָ��ý����Һ�ֽ
rtag=1 rchild ָ��ý��غ��
*/
//���ý���־���������֣����ӽ�㻹��˳����
typedef struct thrnode {
	int data;
	int ltag, rtag;
	struct thrnode *lchild ,*rchild;
}thrnode,*thrtree;



