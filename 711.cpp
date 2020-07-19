#include <iostream>
using namespace std;
int dp[60001];
int main()
{
	//freopen("ans.txt", "w", stdout);
	int a[7], t = 0;
	while((cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6])&&(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]))
	{
		if(t) puts("");
		int sum = a[1]*1+a[2]*2+a[3]*3+a[4]*4+a[5]*5+a[6]*6;
		int m = sum / 2;
		if(sum&1)
		{
            printf("Collection #%d:\n", ++t);
			printf("Can't be divided.\n");
		}
		else
		{
			for(int i = 1; i <= 6; i++)
			{
				if(a[i] * i > m)
				{
					for(int j = i; j <= m; j++)
					    dp[j] = max(dp[j], dp[j-i]);
				}
				else
				{
					int k = 1, s, amount;
					s = amount = a[i];
					while(k < s)
					{
						for(int j = m; j >= k*i; j--)
						    dp[j] = max(dp[j], dp[j-k*i]+k*i);
						amount -= k;
						k*=2;
					}
					for(int j = m; j >= amount*i; j--)
					    dp[j] = max(dp[j], dp[j-amount*i]+amount*i);
				}
			}
			if(dp[m]==m)
			{
                printf("Collection #%d:\n", ++t);
				printf("Can be divided.\n");
			}
			else
			{
                printf("Collection #%d:\n", ++t);
				printf("Can't be divided.\n");
			}
		}
	}

	return 0;
}
