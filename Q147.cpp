#include <iostream>

using namespace std;

int main()
{
	int a, b;
	long long int dp[30010];
	const int coin[11] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int j = 10; j >= 0; j--)
		for(int i = 0; i < 30010; i++)
			if(i - coin[j] >= 0) dp[i] += dp[i-coin[j]];
	while(scanf(" %d.%d",&a, &b)&&(a||b))
	{
		int money = a * 100 + b;
		printf("%3d.%02d%17lld\n",a,b,dp[money]);
	}

	return 0;
}
