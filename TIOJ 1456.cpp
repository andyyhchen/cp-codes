#include <iostream>
#include <vector>
using namespace std;
vector <int> adj[1001];
int indeg[1001] ,order[1001], n, m, a, b, i, j, v, can;
int main()
{
	while(~scanf(" %d %d", &n, &m)){
		for(i = 0; i <= n; i++){
			adj[i].clear();
			indeg[i] = 0;
		}
		for(i = 0; i < m; i++){
			scanf(" %d %d", &a, &b);
			adj[a].push_back(b);
			indeg[b]++;
		}
		for(i = 0; i < n; i++)scanf(" %d", &order[i]);
		can = true;
		for(i = 0; i < n; i++){
			v = order[i];
			if(indeg[v]){
				can = false;
				break;
			}else
				for(j = adj[v].size() - 1; j >= 0; j--)	indeg[adj[v][j]]--;
		}
		if(can)printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
