#include <iostream>
using namespace std;
int p[1010], w[1010], pavw[110], dp[35][30010];
int main()
{
    int t, n, g;
    scanf(" %d", &t);
    while(t--){
        scanf(" %d", &n);
        for(int i = 0; i < n; i++){
            scanf(" %d %d", &p[i], &w[i]);
        }
        scanf(" %d", &g);
        for(int i = 0; i < g; i++){
            scanf(" %d", &pavw[i]);
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < g; i++){
            for(int j = 0; j < n; j++){
                for(int k = pavw[i]; k >= w[j]; k--){
                    dp[i][k] = max(dp[i][k], dp[i][k - w[j]] + p[j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < g; i++){
            ans += dp[i][pavw[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}
