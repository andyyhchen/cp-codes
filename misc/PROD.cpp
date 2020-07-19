#include <iostream>

using namespace std;
int dp[1000010];

int main()
{
	int n;
	dp[1] = 0;
	for(int i = 2; i < 1000010; i++)
		dp[i] = (dp[i-1] + 2) % i;
	while(~scanf(" %d", &n))
		cout << dp[n] + 1 << "\n";
	return 0;
}
