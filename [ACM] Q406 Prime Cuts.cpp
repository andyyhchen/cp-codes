#include<stdio.h>
#include<string.h>
char prime[1001] = {1};
void Build(void)
{
	memset(prime, 1, 1001);
	int i, j;
	prime[0] = 0;
	for(i = 2; i < 34; i++)
	{
		for(j = 2; j < 1001; j++)
		{
			if((j % i == 0) && j != i && prime[j])
			    prime[j] = 0;
		}
	}
}

int main()
{
	int s, e, n, i;
	Build();
	
	while(~scanf(" %d %d", &e, &s))
	{
		n = 0;
		printf("%d %d: ", e, s);
		for(i = s; i <= e; i++)
		{
			if(prime[i])
			    n++;
		}
		if(n % 2)
		    e = ((e * 2) - 1) % (n + 1);
		else
		    e = (e * 2) % (n + 1);
		i = 0;
		
		while(e)
		{
			if(prime[i])
			{
				printf("%d ", i);
				e--;
			}
			i++;
		}
		printf("\n");
	}
    return 0;
}
