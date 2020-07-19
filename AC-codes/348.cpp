#include <iostream>
using namespace std;
int dp[11][11], p[11], s[11][11];
void print(int i, int j)
{
	if(i==j) printf("A%d",i);
	else
	{
		printf("(");
		print(i,s[i][j]);
		printf(" x ");
		print(s[i][j]+1,j);
		printf(")");
	}
}
int main()
{
	int n, c = 0;
	while(cin>>n&&n)
	{
		for(int i = 1; i <= n; i++) cin>>p[i-1]>>p[i];
		for(int i = 0; i <= n ; i++) dp[i][i] = 0;
		for(int i = 2; i <= n; i++)
		{
			for(int j = 1; j <= n - i + 1; j++)
			{
				int r = i + j - 1;
				dp[j][r] = INT_MAX;
				for(int k = j; k < r; k++)
				{
					if(dp[j][r]>dp[j][k]+dp[k+1][r]+p[j-1]*p[k]*p[r])
					{
                        dp[j][r] = dp[j][k]+dp[k+1][r]+p[j-1]*p[k]*p[r];
						s[j][r] = k;
					}
				}
			}
		}
		printf("Case %d: ",++c);
		print(1,n);
		printf("\n");
	}
	return 0;
}
