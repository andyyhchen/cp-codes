#include <iostream>
#include <vector>
using namespace std;
int k, n;
vector <int> adj[201];
int color[201], f = false;
void dfs(int v, int c)
{
	int s = adj[v].size();
	color[v] = c;
	for(int i = 0; i < s; i++)
	{
		if(color[adj[v][i]]==0)
			dfs(adj[v][i], -c);
		else if(color[adj[v][i]]==c) 
		{
			f = true;
			return;
		}
	}
}

int main()
{
	int t, a, b;
	while(scanf(" %d", &n)&&n)
	{
		scanf(" %d", &k);
		for(int i = 0; i <= n; i++) 
			adj[i].clear();
		f= false;
		memset(color, 0, sizeof(color));	
		for(int i = 0; i < k; i++)
		{
			scanf(" %d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(0,1);
		if(!f)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}
}
