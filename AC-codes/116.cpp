#include <iostream>
using namespace std;
int a[11][101], dp[11][101];
void print(int i, int j)
{

}
int main()
{
	int m, n;
	while(cin>>m>>n)
	{
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				scanf(" %d", &a[i][j]);

		memset(dp, 0, sizeof(dp));
		
		for(int j = 1; j <= n; j++)
		{
			for(int i = 0; i < m; i++)
			{
				if(i+1>=m)
					dp[i][j] = min(dp[0][j-1], min(dp[i-1][j-1],dp[i][j-1]));
				else if(i-1<0)
				    dp[i][j] = min(dp[m-1][j-1], min(dp[i+1][j-1], dp[i][j-1]));
				else
				    dp[i][j] = min(dp[i][j-1], min(dp[i+1][j-1], dp[i-1][j-1]));
				dp[i][j]+=a[i][j-1];
			}
		}
		cout<<dp[m-1][n]<<"\n";
	}

	return 0;
}
