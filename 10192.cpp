#include <iostream>
using namespace std;
int main()
{
    char a[101], b[101], st1, st2;
    int dp[2][102], t = 0;
    
    while(gets(a) && a[0] != '#'){
        gets(b);
        st1 = strlen(a), st2 = strlen(b);
        memset(dp, 0, sizeof(dp));
        int cur = 0;
        for(int i = 1; i <= st1; i++){
            for(int j = 1; j <= st2; j++){
                if(a[i - 1] == b[j - 1]) dp[cur][j] = dp[1 - cur][j - 1] + 1;
                else dp[cur][j] = max(dp[cur][j - 1], dp[1 - cur][j]); 
            }
            cur = 1 - cur;
        }
        printf("Case #%d: you can visit at most %d cities.\n", ++t, dp[1 - cur][st2]);        
    }
}
