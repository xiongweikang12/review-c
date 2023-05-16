#include <stdio.h>
#include <stdlib.h>
#include "eachLinkList.h"
//双向链表

each_LinkList Creat_eachLinklist(void)
{
	each_LinkList return_type= (each_LinkList*)malloc(sizeof(each_LinkList));
	return return_type;
}

void init_each_linkList(each_LinkList eL)
{
	if (eL)
	{
		eL->next = NULL; //头结点置空
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
	//计算链表的长度
	int len = each_linkList_length(eL);
	eachLnode* p = eL;
	//插入分为三种情况
	//第一个元素插入
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
	//遇到-1时候停止
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
				printf("插入成功");
			}
			else
			{
				printf("插入失败");
			}
		}

	}
}

void visit_eachLinkList(const each_LinkList eL ,int isHead)
{
	//int 表示是否是有头结点 ,0表示有，非0表示没有
	eachLnode* each_pointer = isHead == 0 ? eL->next : eL; //表示跳过一个结点
	while (each_pointer) //表示为最后一个结点
	{
		printf("%d->", each_pointer->data);
		each_pointer = each_pointer->next;
	}
	printf("\n");
}

eachLnode* serach_eachnode(int location,const each_LinkList eL) 
//根据位序返回对应指向结点的指针
{
	int counter = 0;
	eachLnode* p = eL->next;
	if (location<0 || location>each_linkList_length(eL))
	{
		return NULL; //非法输入，表示未找到
	}
	else
	{
		while (p)
		{
			if (++counter==location)
			{
				return p; //表示找到
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
		return NULL;//表示删除失败
	}
	else if (location==each_linkList_length(eL))
	{
		//表示删除最后一个结点
		eachLnode* p = eL->next;
		while (p->next) { p = p->next; } //对于删除最后一个通过定位到最后，操作其前驱将其删除
		eachLnode* op = p->pri;
		op->next = p->next;
		free(p);
		return op; 
	}
	else
	{
		//表示在正常位置删除
		eachLnode* p = eL->next;
		while (1) {
			if (counter++ == location - 1) { break; }
			else
			{
				p = p->next;
			}
		}

		//定位到前序对其操作
		eachLnode* temp = p->next;
		p->next = temp->next;
		temp->next->pri = p;
		free(temp);
		return p;
	}

}

void insert_eachNode_bypointer(const each_LinkList eL, eachLnode *insert_Lnode ,eachLnode *op_pointer)
{
	//insert_Lnode :插入内容
	// op_pointer :插入位置
	//传入指针，相当于对其操作定位，相当于后继结点
	//这里的结点信息用指针表示，因此可以表示一个结点，也可以表示为一串链表
	eachLnode* op_pir = op_pointer->pri; //前驱
	op_pir->next = insert_Lnode;
	insert_Lnode->pri = op_pir;
	while (insert_Lnode->next){insert_Lnode = insert_Lnode->next;}
	//表示到达最后一个节点
	insert_Lnode->next = op_pointer;
	op_pointer->pri = insert_Lnode;

	/*注意其 insert_Lnode  op_pointer 不能有公共的部分，否则会成环在公共部分*/
}

int Delete_eachnode_bypointer(const each_LinkList eL, int num, eachLnode* delete_location)
{
	//num:删除的数目
	//delete_location:开始删除的位置
	if (delete_location == NULL || delete_location == eL) { return 0; }
	//表示空指针或指向头结点
	else
	{
		int counter = 1;
		eachLnode* op = delete_location->pri; //操作指针
		eachLnode*  memo= delete_location->next; //记录指针
		eachLnode* del_lnode = delete_location; //释放结点的指针
		while (1)
		{
			eachLnode* free_node = del_lnode;
			if (counter++ == num || memo == NULL)
			{
				//开始逻辑上的删除
				op->next = memo;
				if (memo==NULL){}
				else { memo->pri = op; }
				free(free_node);//释放节点
				return 1;
			}
			del_lnode = del_lnode->next;
			free(free_node);
			memo = memo->next;
		}
	}

}