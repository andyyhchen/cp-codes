#include<stdio.h>
#include<memory.h>
unsigned long long int fib[101];
int search(int d, int n)
{
	int i;
	if(d == 1)
	{
	    return 0;
	}
	if(d == 2)
	{
		return 1;
	}
	else
	{
		i = 1;
		while(!(fib[i] < n && fib[i + 1] >= n))
		{
			i += 1;
		}
		return search(i, n - fib[i]);
	}
	
}
void fib_table(void)
{
	int i;
	memset(fib, 0, sizeof(fib));
	fib[1] = fib[2] = 1;
	for(i = 2 ;i < 101; i++)
	{
	    fib[i] += fib[i - 1] + fib[i - 2];
	    printf("%I64d\n", fib[i]);
	}
}
int main()
{
	int d, n, i;
	fib_table();
	while(~scanf(" %d %d", &d, &n))
	{
		i = 0;
		if(n > fib[d])
		    printf("-1\n");
		else
			printf("%d\n", search(d, n));

	}
	
	
    return 0;
}
