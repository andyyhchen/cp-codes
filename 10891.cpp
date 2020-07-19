#include <iostream>
using namespace std;
int dp[101][101], sum[101][101], a[101];
int main()
{
    int n;
    while(scanf(" %d", &n) && n){
        
        for(int i = 0; i < n; i++){
            scanf(" %d", &a[i]);
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            dp[i][i] = sum[i][i] = a[i];
            for(int j = i + 1; j < n; j++){
                sum[i][j] = sum[i][j - 1] + a[j];
            }
        }
        
        for(int len = 2; len <= n; len++){
            for(int i = 0, j = len + i - 1; j < n; i++, j++){
                int smallest = INT_MAX;
                for(int k = i; k <= j; k++){
                    smallest = min(dp[i][k], min(smallest, dp[k][j]));
                }
                dp[i][j] = sum[i][j] - smallest;
            }
        }
        printf("%d\n", dp[0][n - 1] - (sum[0][n - 1] - dp[0][n - 1]));
    }
}
