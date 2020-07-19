#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int key;
	struct node *PREV;
	struct node *NEXT;
} NODE;
void HashAdd(NODE *root, NODE *in)
{
	in -> PREV = root;
	in -> NEXT = root -> NEXT;
	root -> NEXT = in;
	if(in -> NEXT != NULL)
	in -> NEXT -> PREV = in;
}
NODE* NEW(int key)
{
	NODE *ptr = (NODE*)malloc(sizeof(NODE));
	ptr -> NEXT = ptr -> PREV = NULL;
	ptr -> key = key;
	return ptr;
}
int HashFunction(int key, int HashSize){return (key * key) % HashSize;}

int main()
{
	NODE HASHTABLE[31], *ptr;
	int i;
	for(i = 0; i < 31; i++)
 	{
		HASHTABLE[i].NEXT = HASHTABLE[i].PREV = NULL;
		HASHTABLE[i].key = -1;
	}
	for(i = 0; i < 130; i++)
		HashAdd(&HASHTABLE[HashFunction(i, 31)], NEW(i));
	for(i = 0; i < 31; i++)
	{
		ptr = HASHTABLE[i].NEXT;
		for(int j = 0;; j++)
		{
			if(ptr == NULL) break;
			printf("%d ", ptr -> key);
			ptr = ptr -> NEXT;
		}
	}
	system("pause");
	return 0;
}
