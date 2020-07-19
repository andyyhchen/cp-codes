#include <iostream>
using namespace std;
int a[251], sum[251][251], dp[251][251];
int s[251][251];
int main()
{
    int n;
    while(~scanf(" %d", &n)){
        for(int i = 1; i <= n; i++){
            scanf(" %d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            sum[i][i] = a[i];
            for(int j = i + 1; j <= n; j++){
                sum[i][j] = a[j] + sum[i][j - 1];
            }
        }
        int d;
        for(int i = 0; i <= n; i++){
            s[i][i] = i;
            dp[i][i] = 0;
        }
        for(int len = 2; len <= n; len++){
            for(int i = 1, j = i + len - 1; j <= n; i++, j++){
                dp[i][j] = 1000000000;
                for(int k = s[i][j - 1]; k <= s[i + 1][j]; k++){
                    if(dp[i][j] > dp[i][k - 1] + dp[k + 1][j] + sum[i][k - 1] + sum[k + 1][j]){
                        dp[i][j] = dp[i][k - 1] + dp[k + 1][j] + sum[i][k - 1] + sum[k + 1][j];
                        s[i][j] = k;
                    }
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
}
