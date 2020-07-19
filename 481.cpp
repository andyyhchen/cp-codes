#include <iostream>
using namespace std;
int a[100001], g[100001], p[100001];
int stack[100001], top = 0;
int main()
{
    int t, s, v, n;
    for(n = 0; ~scanf(" %d", &a[n]); n++);
    fill(g, g + 100001, 2147483647);
    for(int i = 0; i < n; i++){
        int v = lower_bound(g, g + 100000, a[i]) - g;
        g[v] = a[i];
        p[i] = v;
    }
    s = t = lower_bound(g, g + 100000, 999999999) - g - 1;
    top = 0;
    for(int i = n - 1; i >= 0; i--){
        if(p[i] == t){
            stack[top++] = a[i];
            t--;
        }
    }
    printf("%d\n-\n", s + 1);
    for(int i = top - 1; i >= 0; i--)
        printf("%d\n", stack[i]);
}
