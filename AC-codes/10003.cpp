#include <iostream>
using namespace std;
int a[55], dp[55][55];
int main()
{
    int L, N;
    while(scanf(" %d", &L) && L){
        scanf(" %d", &N);
        for(int i = 1; i <= N; i++){
            scanf(" %d", &a[i]);
        }
        a[0] = 0;
        a[++N] = L;
        for(int i = 0; i <= N; i++) dp[i][i] = 0;
        for(int len = 2; len <= N; len++){
            for(int i = 0, r = i + len; r <= N; i++, r++){
                dp[i][r] = 100000000;
                for(int k = i + 1; k < r; k++){
                    dp[i][r] = min(dp[i][k] + dp[k][r] + a[r] - a[i], dp[i][r]);
                }
            }
        }
        printf("The minimum cutting is %d.\n", dp[0][N]);
    }
}
