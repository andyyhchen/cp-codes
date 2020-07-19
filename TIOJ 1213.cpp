#include <iostream>
#include <vector>
using namespace std;
struct edge{
    int dst, w;
};
vector <edge> adj[100001];
bool visit[100001];
int m, f;
int dfs(int pred, int w)
{
    visit[pred] = 1;
    for(int i = adj[pred].size() - 1; i >= 0; i--){
        if(!visit[adj[pred][i].dst]){
            if(w + adj[pred][i].w > m){
                m = w + adj[pred][i].w;
                f = adj[pred][i].dst;
            }
            dfs(adj[pred][i].dst, adj[pred][i].w + w);
        }
    }
}
int main()
{
    int n;
    while(scanf(" %d", &n) && n){
        for(int i = 0; i < n; i++){
            adj[i].clear();
        }
        int a, b, c;
        edge t;
        for(int i = 1; i < n; i++){
            scanf(" %d %d %d", &a, &b, &c);
            t.w = c;
            t.dst = b - 1;
            adj[a - 1].push_back(t);
            t.dst = a - 1;
            adj[b - 1].push_back(t);
        }
        m = f = 0;
        memset(visit, 0, sizeof(visit));
        dfs(0, 0);
        m = 0;
        memset(visit, 0, sizeof(visit));
        dfs(f, 0);
        printf("%d\n", m);
    }
}
