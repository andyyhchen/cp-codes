#include<stdio.h>
#include<stdlib.h>
int main()
{
	int dp[100], i = 0, in = 0;
	dp[0] = 1;
	dp[1] = dp[2] = 2;
	for( i = 3; i < 76; i++)
		dp[i] = dp[i - 2] + dp[i - 3];
	while(~scanf("%d", &in))
		printf("%d\n", dp[in - 1]);
    return 0;
}
