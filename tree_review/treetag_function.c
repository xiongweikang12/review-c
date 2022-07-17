//线索二叉树相关函数
//
#include "treetag.h"
#include <stdio.h>

//中序线索化

static thrtree pre = NULL;
//全局变量，用于存储后继
//起始右孩子非空


void Inthreading(thrtree T)
{	
	if (T)
	{
		Inthreading(T->lchild);
		if (!(T->lchild)) //表示为空线索前驱
		{
			T->lchild = pre; //前驱
			T->ltag = 1;
		}
		else
		{
			T->ltag = 0;
		}
		if (!(pre->rchild))  //递归返回,pre在T上
		{
			pre->ltag = 1;
			pre->rchild = T; //后继
		}
		else
		{
			pre->rchild = 0;
			pre = T; //指向最后，等待递归返回
		}
		Inthreading(T->rchild);
	}

}


void Inodertravse_tr(thrtree T)
{
	thrtree p = T->lchild; //指向头结点的右孩子后继
	while (p!=T) //表示为遍历完成
	{
		while (p->ltag==0) //表示非空
		{
			p = p->lchild;
			printf("\n线索访问 ：%d", p->data);
		}
		while (p->rtag==1 &&p!=T)
		{
			p = p->rchild; //表示右孩子后继
			printf("\n线索访问 :%d", p->data);
		}
		//转到后继也即是中根开始右线索遍历
		p = p->rchild; //转到右孩子 
	}
}