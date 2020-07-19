#include <iostream>
using namespace std;
unsigned long long int c[1001], dp[1001][1001], r[1001], sum;
int main()
{
	int t, n;
	scanf(" %d", &t);
	sum = 0;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> r[i] >> c[i];
			dp[i][i] = 0;
		}
  		for(int len = 1; len < n; len++){
			for(int i = 0, j = len; i + len < n; i++, j++){
				dp[i][j] = INT_MAX;
				for(int k = i; k < j; k++){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + r[i] * c[k] * c[j]);
				}
			}
		}
		sum += dp[0][n - 1];
		cout << (dp[0][n - 1]+999)/1000 << "\n";
	}
    cout << (sum+999)/1000 << "\n";
	return 0;
}
