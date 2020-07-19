#include<stdio.h>
#include<string.h>
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
	int a[101][101], sum[101], max, n, i, j, k, len;
	while(~scanf(" %d", &n))
	{
		max = -2147483647;
		
	while(scanf(" %s", a[0]))
	{
		len = strlen((char*)a);

		for(int i = 1; i < len; i++) scanf(" %s", a[i]);
		
		for(i = 0; i < len; i++)
		{
			for(j = 0; j < len; j++)
			{
				
				if(a[i][j] == 0) a[i][j] = -10000000;
			}
		}
		for(i = len - 1; i >= 0; i--)
		{
			reset(len, sum);
			for(j = i; j >= 0; j--)
			{
				for(k = 0; k < len; k++)
					sum[k] += a[j][k];
				max = maxf(max, max_1D(sum, len));
			}

		}
		printf("%d\n", max);
	}
    return 0;
}
