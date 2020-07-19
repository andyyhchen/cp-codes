#include <iostream>
using namespace std;
int dp[2][25001];
int main()
{
	int m, t, a[101];
	cin>>t;
	while(t--&&cin>>m)
	{
		int sum = 0;
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= m; i++) cin>>a[i], sum+=a[i];
		int cur = 0;
		int d = sum / 2;
		for(int i = 1; i <= m; i++)
		{
			for(int j = d; j >= a[i]; j--)
				dp[cur][j] = max(dp[1-cur][j],dp[1-cur][j-a[i]]+a[i]);
			cur = 1 - cur;
		}
		cout<<abs(sum - dp[1-cur][d] * 2)<<"\n";
	}
	
}
