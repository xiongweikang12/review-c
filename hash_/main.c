#include <stdio.h>
#include "hash.h"
#include <stdlib.h>
#include "hash_link.h"

void main()
{
	//¼ÙÉèmodÎª5
	//HashTable ha;
	Hash_link ha;
	intiHT(ha, 10);
	KeyType key[] = { 16,26,15,48,79,46,13,45,16,END_INPUT_NUM};
	CreatHL(ha, 5, key);
	DisplayHL(ha, 5);
}