
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
	printf("A�ĺ�����Ŀ%d\n", child_num);
	printf("A�ĺ����У�%c,%c\n", return_child1[0], return_child1[1]);
	printf("B��parentΪ%c\n", return_parent(Tc, 'B').info);
	test_hf(); //�ɹ�
	return 1;
}