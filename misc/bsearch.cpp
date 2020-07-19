#include<stdio.h>
int bisearch(int s, int e, int k, int *a)
{
	int mid = (s + e) / 2;
	if(s > e)
	    return -1;
	if(a[mid] == k)
	    return mid;
	if(a[mid] > k)
	    return bisearch(s, mid - 1, k, a);
	else
	    return bisearch(mid + 1, e, k, a);
}
int bsearch(int s, int e, int k, int *a)
{
	int mid;
	while(s < e)
	{
		mid = (s + e) / 2;
		if(a[mid] == k)
			return mid;
		if(a[mid] > k)
		{
			e = mid - 1;
			continue;
		}
		else
		{
			s = mid + 1;
			continue;
		}
	}
	return -1;
}
int main()
{
	int in[100];
	for(int i = 0; i < 100; i++)
		in[i] = i + 100;
	printf("%d ", bsearch(0, 99, 150, in));
	while(1);
	
	
    return 0;
}
