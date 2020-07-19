#include <iostream>
#define Max 10

using namespace std;

typedef struct node{
	int v;
	struct node *next;
} NODE;

NODE *vertex[Max];

NODE *newNode(int in)
{
	NODE *ptr = (NODE *)malloc(sizeof(NODE));
	ptr -> next = NULL;
	ptr -> v = in;
	return ptr;
}

void EdgeInsert(NODE **vertex, NODE *in)
{
	in -> next = *vertex;
	*vertex = in;
}


int main()
{
	for(int i = 0; i < Max; i++) vertex[i] = NULL;
	int a, b;
	while(~scanf(" %d %d", &a, &b))
	{
		if(!(a && b)) break;
		EdgeInsert(&vertex[a], newNode(b));
        EdgeInsert(&vertex[b], newNode(a));
	}
	int i, j;
	NODE *tmp;
	for(i = 0; i < Max; i++)
	{
		tmp = vertex[i];
		while(tmp != NULL)
		{
			printf("(%2d,%2d)", i, tmp -> v);
			tmp = tmp -> next;
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
