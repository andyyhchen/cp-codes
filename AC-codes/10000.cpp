#include <iostream>
using namespace std;
int a[101][101];
int main()
{
    int s, p, q, n, t = 0;
    while(scanf(" %d", &n) && n){
        scanf(" %d", &s);
        --s;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                a[i][j] = -100000000;
                if(i == j) a[i][j] = 0;
            }
        while(scanf(" %d %d", &p, &q) && (p + q)){
            a[p - 1][q - 1] = 1;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[i][j] = max(a[i][k] + a[k][j], a[i][j]);
                }
            }
        }
        int ans = 0, dst = 0;
        for(int i = 0; i < n; i++){
            if(ans < a[s][i]){
                dst = i;
                ans = a[s][i];
            }
        }
       printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++t, s + 1, ans, dst + 1);
    }
    
}
