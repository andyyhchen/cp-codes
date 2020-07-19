#include <iostream>
#include <algorithm>
#include <vector>
#define V 500

using namespace std;

int deg[V];
vector <int> adj[V];
int stack1[1030], stack2[1030],s1=0,s2=0;

void dfs(int v)
{
 	stack1[s1++] = v;
	for(int i = adj[v].size()-1; i>=0 ;i--)
	{
		if(deg[adj[v][i]] && deg[v])
		{
			deg[adj[v][i]]--; deg[v]--;
			dfs(adj[v][i]);
   			while(stack1[s1-1]!=v)
				stack2[s2++] = stack1[--s1];
		}
	}
}

int main()
{
	int M, a, b, min = 2147483647;
	while(scanf(" %d", &M) && M)
	{
		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++)
			{
				adj[i].clear();
			    deg[i]= 0;
			}
		s1=0,s2=0;
		int a, b;
		for(int i = 0; i < M; i++)
		{
			scanf(" %d %d", &a, &b);
			deg[a]++, deg[b]++;
			if(a < min) min = a;
			if(b < min) min = b;
			adj[a].push_back(b); adj[b].push_back(a);
		}
		for(int i = 0; i < V; i++)
			sort(adj[i].begin(), adj[i].end());
		int v;
		for(v = 0; v < V; v++)
			if(deg[v]&1) break;
		if(deg[v]&1)
		{
			printf("%d\n",v);
			dfs(v);
		}
		else
		{
			printf("%d\n",min);
			dfs(min);
		}
		while(s2)
			printf("%d\n",stack2[--s2]);
		printf("\n");
	}

	return 0;
}
