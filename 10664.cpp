#include <iostream>
using namespace std;
int dp[101], a[21];
int main()
{
	int t, n, sum, m;
	char s[1000], *ts;
	cin>>t;
	while(getchar()!='\n');
	while(t--)
	{
		n = sum = 0;
		gets(s);
		ts = strtok(s, " ");
		while(ts!=NULL)
		{
			a[n] = atoi(ts);
			sum+=a[n];
			n++;
			ts = strtok(NULL," ");
		}
		m = sum / 2;
		if(sum&1)
			puts("NO");
		else
		{
			memset(dp, 0, sizeof(dp));
			for(int j = 0; j < n; j++)
				for(int i = m; i >= a[j]; i--)
				    dp[i] = max(dp[i], dp[i-a[j]]+a[j]);

			if(dp[m] == m)
			    puts("YES");
			else
			    puts("NO");
		}
	}

	return 0;
}
