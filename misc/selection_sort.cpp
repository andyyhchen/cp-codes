#include<stdio.h>
int main()
{
	int i, j, a[10000], smallest, record;
	for( i = 0; i < 10000; i++)
	{
		smallest = a[i];
		record = i;
		for( j = i; j < 10000; j++ )
		{
			if( a[j] < smallest)
			{
				smallest = a[j];
				record = j;
			}
		a[record] = a[i];
		a[i] = smallest;
		}
	}
    return 0;
}
