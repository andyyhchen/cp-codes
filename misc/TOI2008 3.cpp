#include <iostream>
using namespace std;
int m, n, a[101], sum, dp[2][100001];
int main()
{
	while(cin>>m>>n)
	{
		while(m--)
		{
			sum = 0;
			memset(dp,0,sizeof(dp));
			for(int i = 1; i <= n; i++) cin>>a[i], sum += a[i];
			if(sum&1)
			{
				printf("No\n");
				continue;
			}
			int  d = sum / 2;
			int cur = 0;
			for(int i = 1; i <= n; i++)
			{
				for(int j = 0; j <= d; j++)
					if(j - a[i] >= 0)
					    dp[cur][j] = max(dp[1-cur][j], dp[1-cur][j-a[i]]+a[i]);
				cur = 1 - cur;
			}
			if(dp[1-cur][d]!=d)
			    printf("No\n");
			else
			    printf("Yes\n");
		}
	}
	return 0;
}
