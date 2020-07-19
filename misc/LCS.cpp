#include <iostream>
#define max(a , b) (a) > (b) ? (a) : (b)
using namespace std;

const int Max = 100;
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
	while(gets(a))
	{
		gets(b);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", LCS(strlen(a) - 1, strlen(b) - 1));
	}
	return 0;
}
