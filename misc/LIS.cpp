#include <iostream>
#define Max(a , b) ((a) > (b)) ? (a) : (b)

using namespace std;

const int MaxSize = 100;
int N, in[MaxSize], dp[MaxSize][MaxSize];

int LIS(int i, int now)
{
	if((in[i] > in[i + 1]) && (!i)) now += 1;
	if(i < N)
	{
		if(dp[i][now]) return dp[i][now];
		if(in[i] >= now)
			return dp[i][now] = Max(LIS(i + 1, in[i]) + 1, LIS(i + 1, now));
		return dp[i][now] = LIS(i + 1, now);
	}
	return 0;
}

int main()
{
	while(~scanf(" %d", &N))
	{
		memset(dp, 0, sizeof(dp));
		
		for(int i = 0; i < N; i++) scanf(" %d", &in[i]);
		printf("%d\n", LIS(0, in[0]));
	}
	
	system("pause");
	
	return 0;
}
