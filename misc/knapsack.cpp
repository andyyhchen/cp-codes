#include <iostream>
#define Max 1000
using namespace std;

int W[Max], V[Max], dp[Max];

void knapsack(int n, int w)
{
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++)
		for(int j = w; j - W[i] >= 0; j++)
			dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
	cout<<dp[w]<<"\n";
}

int main()
{


	return 0;
}
