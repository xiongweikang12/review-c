#include <stdio.h>
#include <stdlib.h>
#include "eachLinkList.h"
//˫������

each_LinkList Creat_eachLinklist(void)
{
	each_LinkList return_type= (each_LinkList*)malloc(sizeof(each_LinkList));
	return return_type;
}

void init_each_linkList(each_LinkList eL)
{
	if (eL)
	{
		eL->next = NULL; //ͷ����ÿ�
		eL->pri = NULL;
	}
}

int each_linkList_length(each_LinkList eL)
{
	each_LinkList p = eL;
	int counter = 0;
	while (p->next)
	{
		counter++;
		p = p->next;
	}
	return counter;
}

int insert_eachNode(const each_LinkList eL, eachLnode* data_node, int location)
{
	//��������ĳ���
	int len = each_linkList_length(eL);
	eachLnode* p = eL;
	//�����Ϊ�������
	//��һ��Ԫ�ز���
	if (location > len + 1)
	{
		return 0;
	}
	else if (location==len+1)
	{
		while (p->next) { p = p->next; }
		data_node->next = NULL;
		data_node->pri = p;
		p->next = data_node;
	}
	else
	{
		p->next->pri = data_node;
		data_node->next = p->next;
		data_node->pri = p;
		p->next = data_node;
	}
	return 1;
}

void build_eachlinkList(each_LinkList eL)
{
	//����-1ʱ��ֹͣ
	int counter = 0;
	int data = -1;
	while (1)
	{
		printf("input each_Lnode data:");
		scanf_s("%d", &data);
		if (data == -1)
		{
			break;
		}
		else
		{
			eachLnode	*insert_build_Lnode = (eachLnode*)malloc(sizeof(eachLnode));
			insert_build_Lnode->data = data;
			if (insert_eachNode(eL,insert_build_Lnode,++counter))
			{
				printf("����ɹ�");
			}
			else
			{
				printf("����ʧ��");
			}
		}

	}
}

void visit_eachLinkList(const each_LinkList eL ,int isHead)
{
	//int ��ʾ�Ƿ�����ͷ��� ,0��ʾ�У���0��ʾû��
	eachLnode* each_pointer = isHead == 0 ? eL->next : eL; //��ʾ����һ�����
	while (each_pointer) //��ʾΪ���һ�����
	{
		printf("%d->", each_pointer->data);
		each_pointer = each_pointer->next;
	}
	printf("\n");
}

eachLnode* serach_eachnode(int location,const each_LinkList eL) 
//����λ�򷵻ض�Ӧָ�����ָ��
{
	int counter = 0;
	eachLnode* p = eL->next;
	if (location<0 || location>each_linkList_length(eL))
	{
		return NULL; //�Ƿ����룬��ʾδ�ҵ�
	}
	else
	{
		while (p)
		{
			if (++counter==location)
			{
				return p; //��ʾ�ҵ�
			}
			p = p->next;
		}
	}
}

eachLnode* Delete_eachnode(int location, const each_LinkList eL)
{
	int counter = 1;
	if (location<0 || location >each_linkList_length(eL))
	{
		return NULL;//��ʾɾ��ʧ��
	}
	else if (location==each_linkList_length(eL))
	{
		//��ʾɾ�����һ�����
		eachLnode* p = eL->next;
		while (p->next) { p = p->next; } //����ɾ�����һ��ͨ����λ����󣬲�����ǰ������ɾ��
		eachLnode* op = p->pri;
		op->next = p->next;
		free(p);
		return op; 
	}
	else
	{
		//��ʾ������λ��ɾ��
		eachLnode* p = eL->next;
		while (1) {
			if (counter++ == location - 1) { break; }
			else
			{
				p = p->next;
			}
		}

		//��λ��ǰ��������
		eachLnode* temp = p->next;
		p->next = temp->next;
		temp->next->pri = p;
		free(temp);
		return p;
	}

}

void insert_eachNode_bypointer(const each_LinkList eL, eachLnode *insert_Lnode ,eachLnode *op_pointer)
{
	//insert_Lnode :��������
	// op_pointer :����λ��
	//����ָ�룬�൱�ڶ��������λ���൱�ں�̽��
	//����Ľ����Ϣ��ָ���ʾ����˿��Ա�ʾһ����㣬Ҳ���Ա�ʾΪһ������
	eachLnode* op_pir = op_pointer->pri; //ǰ��
	op_pir->next = insert_Lnode;
	insert_Lnode->pri = op_pir;
	while (insert_Lnode->next){insert_Lnode = insert_Lnode->next;}
	//��ʾ�������һ���ڵ�
	insert_Lnode->next = op_pointer;
	op_pointer->pri = insert_Lnode;

	/*ע���� insert_Lnode  op_pointer �����й����Ĳ��֣������ɻ��ڹ�������*/
}

int Delete_eachnode_bypointer(const each_LinkList eL, int num, eachLnode* delete_location)
{
	//num:ɾ������Ŀ
	//delete_location:��ʼɾ����λ��
	if (delete_location == NULL || delete_location == eL) { return 0; }
	//��ʾ��ָ���ָ��ͷ���
	else
	{
		int counter = 1;
		eachLnode* op = delete_location->pri; //����ָ��
		eachLnode*  memo= delete_location->next; //��¼ָ��
		eachLnode* del_lnode = delete_location; //�ͷŽ���ָ��
		while (1)
		{
			eachLnode* free_node = del_lnode;
			if (counter++ == num || memo == NULL)
			{
				//��ʼ�߼��ϵ�ɾ��
				op->next = memo;
				if (memo==NULL){}
				else { memo->pri = op; }
				free(free_node);//�ͷŽڵ�
				return 1;
			}
			del_lnode = del_lnode->next;
			free(free_node);
			memo = memo->next;
		}
	}

}