#include "list.h"
#include <stdio.h>

/*ÓÃÓÚ²âÊÔ*/

void main()
{
	SqList* newpointersq = CreatSlist();
	printf("%p\n", newpointersq);
	printf("%d\n", newpointersq->length);
	printf("%p\n",newpointersq->data);
	// DeotroyList(newpointersq);
	initList(newpointersq);
	printf("%p\n", newpointersq->data);
	inputsq(newpointersq);
	visitsq(*newpointersq);
	Listinsert(newpointersq, 2, 4);
	printf("\n");
	visitsq(*newpointersq);
	ListDelete(newpointersq, 2);
	printf("\n");
	visitsq(*newpointersq);

	
}