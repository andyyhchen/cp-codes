#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, dp[1000];
 	vector <int> v;
	char num[10];
	gets(num);
	n = atoi(num);
	while(getchar()!='\n');
	while(n--)
	{
        v.clear();
		while(gets(num)&&*num) v.push_back(atoi(num));
		for(int i = v.size() - 1; i >= 0; i--) dp[i] = 1;
		int len = v.size();
		for(int i = 1; i < len; i++)
			for(int j = 0; j < i; j++)
			    if(v[i]>v[j]) dp[i] = max(dp[i],dp[j]+1);
		int m = 0;
		for(int i =0 ; i < len; i++)
		    m = max(m,dp[i]);
		int t;
		for(int t = 0; t < len; t++)
		    if(dp[t]==m) break;
		int n = m + 1;
 		int stack[1001], s = 0;
		for(int i = t; i >= 0; i--)
		    if(dp[i]==n-1)
		    {
				stack[s++] = v[i];
				n = dp[i];
			}
		printf("Max hits: %d\n", m);
		while(s)
			printf("%d\n", stack[--s]);
		if(n) puts("");
	}
	return 0;
}
