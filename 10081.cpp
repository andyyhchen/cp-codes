#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    //freopen("10081ans.txt","w",stdout);
	double dp[100][10];
	int k,n;
	while(cin>>k>>n)
	{
		for(int i = 0; i < 100; i++)
		    for(int j = 0; j < 10; j++)
		        dp[i][j] = 0.0;
		for(int i = 0; i <= k; i++) dp[1][i] = 1;
		for(int i = 2; i <= n; i++)
		    for(int j = 0; j <= k; j++)
		    {
		        if(j - 1 >= 0) dp[i][j] += dp[i-1][j-1];
		        if(j + 1 <= k) dp[i][j] += dp[i-1][j+1];
		        dp[i][j]+=dp[i-1][j];
			}
		double sum = pow((k+1)*1.0,(n*1.0))+10e-9;
		double s = 0;
		for(int i = 0; i <= k; i++) s+=dp[n][i];
		printf("%.5f\n", (s*100.0) / sum+10e-9);
	}
	return 0;
}
