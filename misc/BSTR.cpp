#include <iostream>
#define hash(x) ((x) * (x)) % 101

using namespace std;

typedef struct node{
	int data;
	int key;
	bool d;
	struct node *left;
	struct node *right;
} NODE;

NODE* newNode(int in)
{
	NODE *ptr = (NODE *)malloc(sizeof(NODE));
	ptr->left = ptr->right = NULL;
	ptr->data = in;
	ptr->key = hash(in);
	ptr->d = true;  // is exist
	return ptr;
}

NODE* search(int in, NODE *root)
{
	if(root == NULL) return NULL;
	if(root->key == hash(in) && root->d && root->data == in) return root;
	if(root->key>=hash(in)) return search(in, root->left);
	else return search(in, root->right);
}

void insert(NODE *in, NODE *root)
{
	NODE *tmp = root, *target = NULL;
	char direction;
	while(tmp!=NULL)
	{
		target = tmp;
		if(in->key > tmp->key)
		{
			tmp = tmp->right;
			direction = 1;
		}
		else
		{
		    tmp = tmp->left;
		    direction = 2;
		}
	}
	if(direction == 1)
		target->right = in;
	else
	    target->left = in;
}

void deletion(NODE *in)
{
	in->d = false;
}
int main()
{
	NODE *root = newNode(10);
	for(int i = 0; i < 100000; i++)
	    insert(newNode(i), root);
/*	for(int i = 0; i < 30; i++)
	{
		deletion(search(i, root));
	}
	for(int i = 0; i < 1000; i++)
	    if(search(i, root)!=NULL) printf("%d\n",i);*/

	system("pause");
	return 0;
}
