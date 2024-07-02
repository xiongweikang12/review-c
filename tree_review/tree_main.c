
#include "tree_child.h"
#include <stdio.h>
#include<stdlib.h>

int main()
{
	tree_child *Tc = (tree_child*)malloc(sizeof(tree_child));
	creat_tree__child(Tc);
	build_child_tree(Tc);
	return 1;
}