#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int key;
	struct node *left;
	struct node *right;
} NODE;
NODE *NEW(int key)
{
	NODE *ptr = (NODE *)malloc(sizeof(NODE));
	ptr -> left = ptr -> right = NULL;
	ptr -> key = key;
	return ptr;
}
void Insert(NODE *root, NODE *in)
{
	int key = in -> key;
	NODE *ptr = root;
	while(ptr != NULL)
	{
		root = ptr;
		if(ptr -> key > key)
			ptr = ptr -> left;
		else
			ptr = ptr -> right;	
	}
	if(root -> key > key)
		root -> left = in;
	else
		root -> right = in;	
}
void PreOrder(NODE *root)
{
	if(root == NULL) return;
	printf("%d ", root -> key);
	PreOrder(root -> left);
	PreOrder(root -> right);
}
void InOrder(NODE *root)
{
	if(root == NULL) return;
	InOrder(root -> left);
	printf("%d ", root -> key);
	InOrder(root -> right);
}
void PostOrder(NODE *root)
{
	if(root == NULL) return;
	PostOrder(root -> left);
	PostOrder(root -> right);
	printf("%d ", root -> key);
}
NODE* Search(NODE *root, int key)
{
	if(root == NULL) return NULL;
	if(root -> key == key) return root;
	if(root -> key > key) root = root -> left;
	else root = root -> right; 
	return Search(root, key); 
}
NODE* SP(NODE *root, NODE *target)   // SearchParent
{
	if(target == NULL) return NULL;
	if(root == NULL) return NULL;
	if(root -> left == target || root -> right == target) return root;
	if(root -> key > target -> key)
	    root = root -> left;
	else
	    root = root -> right;
	return SP(root, target);
}
void Delete(NODE *root, int key)
{
	NODE *target = Search(root, key);
	NODE *ptr, *successor = NULL, *parent = NULL;
	if(target == NULL) return;
	parent = SP(root, target);
	if(target -> left == NULL && target -> right == NULL)
	    successor = NULL;
	if(target -> left != NULL && target -> right == NULL)
	    successor = target -> left;
	if(target -> left == NULL && target -> right != NULL)
	    successor = target -> right;
	if((target -> left != NULL) && (target -> right != NULL))
	{
		ptr = target -> right;
		while(ptr -> left != NULL)
			ptr = ptr -> left;
		target -> key = ptr -> key;
		SP(root, ptr) -> left = ptr -> right;
		successor = ptr;
	}
	if(parent -> key > target -> key)
		    parent -> left = successor;
	else
		    parent -> right = successor;
}
int main()
{
	int i = 0; 
	NODE *root = NEW(1010);
	for(i = 0; i < 10; i++)
	{
		Insert(root, NEW(i % 4));
	}
	
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n"); 
	PostOrder(root);
	printf("\n");
	system("pause");
	
	
}
