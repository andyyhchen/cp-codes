#include<stdio.h>
int main()
{
	int n, i, j, k, p, a[101][101], sum = 0, max = 0;
	while( ~ scanf(" %d", &n))
	{
		max = 0;
		sum = 0;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				scanf(" %d", &a[i][j]);
			}
		}

		for(i = n - 1; i >= 0; i--)
		{
			for(j = 0; j <= i; j++)
			{
				sum = 0;
				for(k = 0; k < n; k++)
				{
					for(p = j; p <= i; p++)
					    sum += a[k][p];
					if(sum > max)
						max = sum;
					if(sum < 0)
					    sum = 0;
				}
			}
		}
		printf("%d\n", max);
	}
    return 0;
}


