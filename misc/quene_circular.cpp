#include<stdio.h>
#define QSIZE 10
int EQUENE(int in, int *quene, int *head, int *tail)
{
	if((*tail + 1) % QSIZE == *head)
	    return 0;
	else
		*tail = (*tail + 1) % QSIZE;
	    quene[*tail] = in;
	return 1;
}
int DEQUENE(int *quene, int *head, int *tail)
{
	if((*head + 1) % QSIZE == *tail)
	    return 0;
	else
	    *head = (*head + 1) % QSIZE;
	    return quene[*head];
	    
}
int main()
{
	int quene[QSIZE + 1], head = 0, tail = 0;
	while(EQUENE(210, quene, &head, &tail));
	{
		printf("%d ", quene[tail]);
	}
	while(DEQUENE(quene, &head, &tail));
	{
		printf("%d ", quene[head]);
	}
	while(1);
    return 0;
}
