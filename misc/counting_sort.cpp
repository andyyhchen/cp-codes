#include<stdio.h>
#define MAX 100000
void csort(int *a, int *b)
{
	int c[MAX], i, j, co = 0;
	for(i = 0; i < MAX; i++)
	    c[i] = 0;
	for(i = 0; i < MAX; i++)
	    c[a[i]] += 1;
	for(i = 0; i < MAX; i++)
	{
		for(j = 0; j < c[i]; j++)
		    b[co + j] = i;
		co = co + j;
	}
}

int main()
{
	int y, ara[MAX], arb[MAX];
	for(y = 0; y < MAX; y++)
		ara[y] = MAX - y;
	csort(ara, arb);
	for(y = 0; y < MAX; y++)
	    printf("%d ", arb[y]);
	while(1);
    return 0;
}
