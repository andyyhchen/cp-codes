#include <iostream>
using namespace std;
int main()
{
	int a, n, standard_ans[21], student_ans[21], dp[2][21];
	while(cin>>n)
	{
		for(int i = 0; i < n; i++)
		{
			cin>>a;
			standard_ans[a-1] = i;
		}
		while(cin>>a)
		{
			student_ans[a-1] = 0;
			for(int i = 1; i < n; i++)
			{
				cin>>a;
				student_ans[a-1] = i;
			}
			for(int i = 0; i <= n; i++)
			    dp[1][i] = dp[0][i] = 0;
			int cur = 1;
			for(int i = 1; i <= n; i++)
			{
		    	for(int j = 1; j <= n; j++)
					if(standard_ans[i-1]==student_ans[j-1]) dp[cur][j] = dp[1-cur][j-1]+1;
					else dp[cur][j] = max(dp[cur][j-1],dp[1-cur][j]);
				cur = 1 - cur;
			}
			cout<<dp[1-cur][n]<<"\n";
		}
		    
	}
	
	
	return 0;
}
