#include<stdio.h>
void reset(int n, int *c)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		c[i] = 0;
	}
}
int maxf(int a, int b)
{
	return (a > b) ? a : b;
}
int max_1D(int *b, int n)
{
    int sumtmp = 0,	maxtmp = -2147483647, g;
	for(g = 0; g < n; g++)
	{
		sumtmp += b[g];
		if(sumtmp < 0)
		    sumtmp = 0;
		if(sumtmp > maxtmp)
		    maxtmp = sumtmp;
	}
	return maxtmp;
}

int main()
{
	int a[101][101], sum[101], max, n, i, j, k;
	while(~scanf(" %d", &n))
	{
		max = -2147483647;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				scanf(" %d", &a[i][j]);
			}
		}
		for(i = n - 1; i >= 0; i--)
		{
			reset(n, sum);
			for(j = i; j >= 0; j--)
			{
				for(k = 0; k < n; k++)
					sum[k] += a[j][k];
				max = maxf(max, max_1D(sum, n));
			}

		}
		printf("%d\n", max);
	}
    return 0;
}
