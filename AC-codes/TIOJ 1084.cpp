#include <iostream>
#include <vector>
using namespace std;
int map[510][510], deg[510], st1[1040], st2[1040], s1, s2;
vector <int> adj[510];
void dfs(int s)
{
	st1[s1++] = s;
	int z = adj[s].size();
	for(int i = 0; i < z; i++){
		if(map[s][adj[s][i]] > 0){
			map[s][adj[s][i]]--; map[adj[s][i]][s]--;
			dfs(adj[s][i]);
			while(st1[s1 - 1] != s) st2[s2++] = st1[--s1];
		}
	}
}
int main()
{
	int m, mi;
	while(scanf(" %d", &m) && m){
		mi = 600;
		for(int i = 0; i <= 500; i++){
			for(int j = 0; j <= 500; j++){
				map[i][j] = map[j][i] = 0;
			}
			adj[i].clear();
			deg[i] = 0;
		}
		int a, b;
		for(int i = 0; i < m; i++){
			scanf(" %d %d", &a, &b);
			deg[a]++; deg[b]++;
			adj[a].push_back(b);
			adj[b].push_back(a);
			mi = min(mi, min(a, b));
			map[a][b]++; map[b][a]++;
		}
		for(int i = 0; i <= 500; i++){
			sort(adj[i].begin(), adj[i].end());
		}
		int s;
		s1 = s2 = 0;
		for(int s = 1; s <= 500; s++){
			if(deg[s]%2) break;
		}
		if(deg[s]%2){
			dfs(s);
			printf("%d\n", s);
		}else{
			dfs(mi);
			printf("%d\n", mi);
		}
		while(s2) printf("%d\n", st2[--s2]);
		printf("\n");
	}

	return 0;
}
