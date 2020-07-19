#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
vector <int> adj[20001], branch[20001];
int son[20001], ans[20001], visit[20001], pre[20001], n;
void dfs(int v, int p)
{
	visit[v] = 1;
	pre[v] = p;
	int s = adj[v].size();
	for(int i = 0; i < s; i++){
		if(!visit[adj[v][i]]){
			dfs(adj[v][i], v);
			son[v] += son[adj[v][i]] + 1;
			branch[v].push_back(adj[v][i]);
		}
	}
	return;
}
int main()
{
	while(~scanf(" %d", &n)){
		for(int i = 0; i <= n; i++){
			pre[i] = visit[i] = son[i] = 0;
			adj[i].clear();
			branch[i].clear();
		}
		int a, b;
		for(int i = 1; i < n; i++){
			scanf(" %d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(1, 0);
		vector <int> t;
		for(int i = 1; i <= n; i++){
			int s = branch[i].size(), d = n;
			t.clear();
			t.push_back(0);
			for(int j = 0; j < s; j++){
				t.push_back(son[branch[i][j]] + 1);
				d -= (son[branch[i][j]] + 1);
			}
			d--;
			t.push_back(d);
			s = t.size();
			for(int j = 0; j < s; j++){
				for(int k = j + 1; k < s; k++){
					ans[i] += t[j] * t[k];
				}
			}
		}
		int m = 0;
		for(int i = 1; i <= n; i++) m = max(m, ans[i]);
		for(int i = 1; i <= n; i++){
			if(ans[i] == m){
				printf("%d %d\n", i, m);
				break;
			}
		}
	}

	return 0;
}
