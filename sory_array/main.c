#include <stdio.h>
#include <stdlib.h>
#include "array_sort.h"

void main()
{
	Sqlist* L = (Sqlist*)malloc(sizeof(Sqlist));
	Sqlist* LL = (Sqlist*)malloc(sizeof(Sqlist));
	Input_key(L);
	Input_key(LL);
	// Output_key(*L);
	//Insert_Sort(L);
	// Bubbling_Sort(L);
	//Choice_Sort(L);
	//quick_Sort(L, 0, L->length - 1);
	//Output_key(*L);
	heap_big(L);
	Output_key(*L);
	heap_sort(L, LL);
	Output_key(*LL);
}