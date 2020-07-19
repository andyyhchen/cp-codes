#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	int key;
	int height;
	struct node *left;
	struct node *right;
} NODE;

NODE *NEW(int key)
{
	NODE *ptr = (NODE *)malloc(sizeof(NODE));
	ptr -> right = ptr -> left = NULL;
	ptr -> height = 0;
	ptr -> key = key;
	return ptr;
}

void Insert(NODE *root, NODE *in)
{
	int key = in -> key;
	NODE *ptr = root, *parent = root;
	while(ptr != NULL)
	{
		parent = ptr;
		if(ptr -> key > key)
		{
			ptr -> height++;
			ptr -> left -> height++;
		    ptr = ptr -> left;
		}
		else
		{
            ptr -> height++;
            ptr -> right -> height++;
		    ptr = ptr -> right;
		}
	}
	if(parent -> key > key)
	    parent -> left = in;
	else
	    parent -> right = in;
}
NODE* Search(NODE *root, int key)
{
	if(root == NULL) return NULL;
	if(root -> key == key) return root;
	if(root -> key > key)
	    root = root -> left;
	else
	    root = root -> right;
	return Search(root, key);
}
void Delete(NODE *root, int key)
{
	NODE *target = Search(root, key), *ptr = root -> right;
}

int main()
{

	system("pause");
	return 0;
}
