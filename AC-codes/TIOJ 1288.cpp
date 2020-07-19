#include <stdio.h>
#include <string.h>
#define max(a,b) (a) > (b) ? (a) : (b)
#define N 101
using namespace std;

int main()
{
	int in[N][N], h;
	int dp[2][N];
	while(~scanf(" %d", &h))
	{
		for(int i = 0; i < h; i++)
			for(int j = 0; j <= i; j++)
				scanf(" %d", &in[i][j]);
		memset(dp, 0, N<<2);
		for(int i = 0; i <= h; i++) dp[1][i] = 0;
		for(int i = h - 1; i >= 0; i--)
		{
			for(int j = i; j >= 0; j--)
				dp[0][j] = in[i][j] + max(dp[1][j+1], dp[1][j]);
			for(int j = 0; j <= i; j++) dp[1][j] = dp[0][j];
		}
		printf("%d\n",dp[0][0]);
	}
	return 0;
}
