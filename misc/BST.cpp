#include <iostream>

using namespace std;

typedef struct node{
	int key;
	struct node *right;
	struct node *left;
} NODE;

NODE* CreatNode(int value)
{
	NODE *tmp = (NODE*)malloc(sizeof(NODE));
	tmp->left = tmp->right = NULL;
	tmp->key = value;
	return tmp;
}

void Insert(NODE *root, NODE *target)
{
	int t_key = target->key;
	NODE *tmp = root, *p; bool direction = false;
	while(tmp!=NULL)
	{
		p = tmp;
		if(t_key > tmp->key)
		{
			tmp = tmp->right;
			direction = true;
		}
		else
		{
			tmp = tmp->left;
			direction = false;
		}
	}
	if(direction) p->right = target;
	else p->left = target;
}

NODE* Search(NODE *root, int value)
{
	NODE *tmp = root;
	while(tmp!=NULL)
	{
		if(tmp->key == value) return tmp;
		if(value > tmp->key) tmp = tmp->right;
		else tmp = tmp->left;
	}
	return NULL;
}

bool Deletion(NODE *root, NODE *target)
{
	NODE *tmp = root, *p; bool direction = false;
	if(target==NULL) return false;
	while(tmp!=NULL)
	{
		if(tmp == target) break;
		p = tmp;
		if(target->key > tmp->key)
		{
			tmp = tmp->right;
			direction = true;
		}
		else
		{
			tmp = tmp->left;
			direction = false;
		}
	}
	NODE *successor;
	if(target->left==NULL&&target->right==NULL) successor = NULL;
	else if(target->left==NULL) successor = target->right;
	else if(target->right==NULL) successor = target->left;
	else
	{
		NODE *tmpt = target->right;
		if(tmpt->left == NULL)
		{
			tmpt->left = target -> right;
			successor = tmpt;
		}
		else
		{
			while(tmpt->left->left!=NULL);
			successor = tmpt->left;
			tmpt->left = successor->right;
			successor->left = target->left;
			successor->right = target->right;
		}
	}
	if(direction) p->right = successor;
	else p->left = successor;
	return true;
}

int main()
{



	system("pause");
	return 0;
}
