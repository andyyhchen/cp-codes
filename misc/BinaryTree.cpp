#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int key;
	struct node *L;
	struct node *R;
	struct node *P;
} NODE;

NODE* NewNode(int in)
{
	NODE *ptr = (NODE*)malloc(sizeof(NODE));
	ptr -> L = ptr -> R = ptr -> P = NULL;
	ptr -> key = in;
	return ptr;
}
NODE* Search(int key, NODE *root)
{
	if(root == NULL) return NULL;
	if(root -> key == key) return root;
	return Search(key, (root -> L));
	return Search(key, (root -> R));
}
void Insert(NODE *New, NODE *P)
{
	if(P -> L == NULL)
	{
		P -> R = New;
		New -> P = P;
	}
	else
	{
	    P -> L = New;
	    New -> P = P;
	}
}
void Delete(NODE *now)
{
	if(now -> P -> L == now)
		now -> P -> L = NULL;
	else
	    now -> P -> R = NULL;
	free(now);
}
int main()
{


    return 0;
}
