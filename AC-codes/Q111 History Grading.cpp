#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a , b) (a) > (b) ? (a) : (b)

const int Max = 21;
char a[Max], b[Max];
int dp[Max][Max];

int LCS(int i, int j)
{
	if(i < 0 || j < 0) return 0;
	if((~dp[i][j])) return dp[i][j];
	if(a[i] == b[j])
	   return dp[i][j] = LCS(i - 1, j - 1) + 1;
	return dp[i][j] = max(LCS(i - 1, j), LCS(i, j - 1));
}

int main()
{
	int n, a[21], b[21];
	while(~scanf(" %d", &n))
	{
		for(int i = 0; i < n; i++) scanf(" %d", &a[i]);
		while(~scanf(" %d", &b[0]))
		{
            memset(dp, -1, sizeof(dp));
			for(int i = 1; i < n; i++) scanf(" %d", &b[i]);
			printf("%d\n", LCS(n, n));
		}
		

	}

	system("pause");
	return 0;
}
