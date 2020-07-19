#include <iostream>
using namespace std;
char s1[1010], s2[1010];
int dp[2][1010];
int main()
{
	while(gets(s1)&&gets(s2))
	{
		int len1 = strlen(s1), len2 = strlen(s2);
		int cur = 1;
		for(int i = 0; i < 1010; i++) dp[0][i] = dp[1][i] = 0;
		for(int i = 1; i <= len1; i++)
		{
		    for(int j = 1; j <= len2; j++)
				if(s1[i-1]==s2[j-1]) dp[cur][j] = dp[1-cur][j-1]+1;
				else dp[cur][j] = max(dp[1-cur][j],dp[cur][j-1]);
			cur =  1 - cur;
		}
		cout<<dp[1 - cur][len2]<<"\n";
	}
	return 0;
}
