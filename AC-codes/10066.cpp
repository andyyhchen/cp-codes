#include <iostream>
using namespace std;
int dp[2][110];
int main()
{
	int n1, n2, t;
	int a[110], b[110];
	t = 0;
	while(cin>>n1>>n2 && (n1 + n2))
	{
		for(int i = 0; i < n1; i++)
		    scanf(" %d", &a[i]);
		for(int i = 0; i < n2; i++)
		    scanf(" %d", &b[i]);

		memset(dp, 0, sizeof(dp));
		
		int cur = 0;
		
		for(int i = 1; i <= n1; i++)
		{
		    for(int j = 1; j <= n2; j++)
		        if(a[i - 1] == b[j - 1]) dp[cur][j] = dp[1 - cur][j - 1] + 1;
		        else dp[cur][j] = max(dp[1 - cur][j], dp[cur][j - 1]);
		    cur = 1 - cur;
		}
	    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++t, dp[1-cur][n2]);
	}

	return 0;
}
