#include<stdio.h>
#include<stdlib.h>
struct data{
	int num;
	struct data *next;
	struct data *prev;
	};
typedef struct data NODE;

NODE* creat(int in)
{
	NODE *ptr = NULL;
	ptr = (NODE *)malloc(sizeof(NODE));
	ptr -> num = in;
	return ptr;
}
void ins(NODE *ptr, NODE *head)
{
	(ptr -> next) = head -> next;
	if((head -> next) != NULL)
		( head -> next ) -> prev = ptr;
 	ptr -> prev = head;
	head -> next = ptr;
}
void del(NODE *head)
{
    
	NODE *tmp = NULL;
	if((head -> next) != NULL)
	{
		( head -> next ) -> prev = head;
		tmp = head -> next;
		head -> next = ( head -> next ) -> next;
		free(tmp);
	}
}
NODE *search(int re, NODE now, NODE head)
{
	NODE *find = NULL;
    if(now.num != re)
    {
		if(now.next == NULL)
			return NULL;
	    find = search(re, *(now.next), head);
	}
	if(now.num == re)
	    find = &now;
	return find;
}

		

	
	



int main()
{
	NODE head, *tmp;
	head.num = 2147483647;
	head.prev = NULL;
	head.next = NULL;
	for(int i = 0; i < 100; i++)
	{
		tmp = creat(i);
		ins(tmp, &head);
	}
	for(int i = 0; i < 50; i++)
	    del(&head);
	if(search(7, *(head.next), head) != NULL)
		printf("done\n");
	while(1);
	
    return 0;
}
