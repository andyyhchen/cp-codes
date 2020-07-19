#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int key;
	struct node *left;
	struct node *right;
} NODE;

NODE *NewNode(int key)
{
	NODE *ptr = (NODE*)malloc(sizeof(NODE));
	ptr -> left = ptr -> right = NULL;
	ptr -> key = key;
	return ptr;
}

void Insert(NODE *root, NODE *in)
{
	NODE *parent, *now = root;
	while(now != NULL)
	{
		parent = now;
		if(now -> key > in -> key)
		    now = now -> left;
		else
		    now = now -> right;
	}
	if(parent -> key > in -> key)
	    parent -> left = in;
	else
	    parent -> right = in;
}

NODE* Search(NODE *now, int key)
{
	if(now == NULL) return NULL;
	if(now -> key == key) return now;
	if(now -> key > key)
	    return Search(now -> left, key);
	else
	    return Search(now -> right, key);
}

void Delete(NODE *root, int key)
{

}
int main()
{
	NODE *root = NewNode(100);
	int i;
	for(i = 0; i < 10; i++)
	{
		Insert(root, NewNode(i % 3));
	}
	Delete(root, 2);
	for(i = 0; i < 120; i++)
	{
		if(Search(root, i) != NULL)
	    	printf("done %d \n", i);
	    system("pause");
	}
    return 0;
}
