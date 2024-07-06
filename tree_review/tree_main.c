
#include "tree_child.h"
#include <stdio.h>
#include<stdlib.h>

int main()
{	
	tree_child *Tc = (tree_child*)malloc(sizeof(tree_child));
	creat_tree__child(Tc);
	build_child_tree(Tc);
	char* return_child1 = (char*)malloc(sizeof(char) * Maxsize);
	int child_num = return_child(Tc, 'A', return_child1);
	printf("A的孩子数目%d\n", child_num);
	printf("A的孩子有：%c,%c\n", return_child1[0], return_child1[1]);
	printf("B的parent为%c\n", return_parent(Tc, 'B').info);
	test_hf(); //成功
	return 1;
}