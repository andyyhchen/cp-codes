#include<stdio.h>
int quene[100], head = 0, tail = 1;
int equene(int in)
{
	
	if(tail == head)
	    return 0;
	if(tail > 99)
	    tail = 0;
	else
	{
		quene[tail] = in;
		tail++;
	}
}
int dquene()
{
	printf("%d\n", head);
	if(tail == head)
	    return 0;
	if(head > 99)
	{
		head = 0;
		return quene[head];
	}
	else
	{
		head++;
		return quene[head - 1];
	}
}
int main()
{
	while(equene(100));
	while(dquene());
	while(1);
}
