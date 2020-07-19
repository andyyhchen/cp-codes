#include<stdio.h>
long long int dp[7490];
int main()
{
	int i, j, in;
	int coin[5] = {1, 5, 10, 25, 50};
	for( i = 0; i <= 7490; i++)
		dp[i] = 0;
	dp[0] = 1;
	 for(i = 0; i < 5; i++)
        for(j = coin[i]; j <= 7490; j++)
            dp[j] += dp[j - coin[i]];
	while( ~ scanf(" %d", &in) )
		printf("%lld\n", dp[in]);
	return 0;
}
