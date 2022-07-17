#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void main(void)
{
	Tree* T = (Tree*)malloc(sizeof(Tree));
	creattree(T);
	PreOrderTraverse(*T);

}