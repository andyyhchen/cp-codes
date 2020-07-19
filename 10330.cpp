#include <iostream>
#include <queue>
#define Pout 101
using namespace std;
int capacity[205][205], pre[205];
bool visit[205];
int n, m, a, b, c, nS, nT;
int bfs(int s, int t)
{
	int f = 100000000;
	queue <int> Q;
	memset(visit, 0, sizeof(visit));
	memset(pre, -1, sizeof(pre));
	Q.push(s);
	visit[s] = 1;
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		if(v != s){
			f = min(f, capacity[pre[v]][v]);
		}
		if(v == t) return f;
		for(int i = n + 1 + Pout; i >= 0; i--){
			if(capacity[v][i] > 0 && !visit[i]){
				Q.push(i);
				visit[i] = 1;
				pre[i] = v;
			}
		}
	}
	return 0;
}
int main()
{
	while(~scanf(" %d", &n)){
		memset(capacity, 0, sizeof(capacity));
		for(int i = 1; i <= n; i++){
			scanf(" %d", &a);
			capacity[i][i + Pout] = a;
		}
		scanf(" %d", &m);
		for(int i = 0; i < m; i++){
			scanf(" %d %d %d", &a, &b, &c);
			capacity[a + Pout][b] = c;
		}
		scanf(" %d %d", &nS, &nT);
		for(int i = 0; i < nS; i++){
			scanf(" %d", &a);
			capacity[Pout][a] = 100000000;
		}
		for(int i = 0; i < nT; i++){
			scanf(" %d", &a);
			capacity[a + Pout][n + 1] = 100000000;
		}
  		capacity[n + 1][n + 1 + Pout] = capacity[0][Pout] = 100000000;
  		int f, df;
  		for(f = 0, df = 0; df = bfs(Pout, n + 1); f += df){
			for(int i = n + 1; pre[i] >= 0; i = pre[i]){
				capacity[pre[i]][i] -= df;
				capacity[i][pre[i]] += df;
			}
		}
		printf("%d\n", f);
	}
	return 0;
}
