#include<stdio.h>
long long int bigmod(long long int pow, long long int n, long long int m)
{
	long long int ans = 0;
	if(pow == 1)
	    return n % m;
	else
	{
		if(pow % 2)
		{
			ans = bigmod(pow / 2, n, m);
			return (((ans * ans) % m) * (n % m)) % m;
		}
		else
		{
			ans = bigmod(pow / 2, n, m);
			return (ans * ans) % m;
		}
	}

}
int main()
{
	long long int B, P, M;
	while(~scanf(" %lld", &B))
	{
		scanf(" %lld", &P);
		//scanf(" %lld", &M);
		M = 10007;
		if(!P)
		    printf("%d\n", 1 % M);
		else
			printf("%lldd\n", bigmod(P, B, M));
	}
    return 0;
}
