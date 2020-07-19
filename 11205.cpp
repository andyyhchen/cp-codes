#include <iostream>
using namespace std;
bool v[32770];
int main()
{
    int t, p, n, a[101], in, k;
    scanf(" %d", &t);
    while(t-- && scanf(" %d %d", &p, &n)){
        for(int i = 0; i < n; i++){
            in = 0;
            for(int j = p - 1; j >= 0; j--){
                scanf(" %d", &k);
                in |= k << j;
            }
            a[i] = in;
        }
        int ans = 0, bound = 1 << p, f, min = INT_MAX;
        for(int i = 0; i < bound; i++){
            f = 0;
            memset(v, 0, sizeof(v));
            for(int j = 0; j < n; j++){
                if(v[a[j] & i]){
                    f = 1;
                    break;
                }else{
                    v[a[j] & i] = 1;
                }
            }
            if(!f){
                ans = i;
                int c = 0;
                for(int i = 0; i < p; i++){
                    if(((ans >> i) & 1))
                        c++;
                }
                if(c < min) min = c;       
            }
        }
        printf("%d\n", min); 
    }
}
