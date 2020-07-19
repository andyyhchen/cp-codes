#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, s, t;
struct edge{
	int dst, w;
};
vector <edge> adj[1001];
int main()
{
	while(~scanf(" %d %d", &n, &m))
	{
		int a, b, w;
		edge t_edge;
		for(int i = 0; i < n; i++)
			adj[i].clear();
		scanf(" %d %d", &s, &t);
		--s; --t;
		for(int i = 0; i < m; i++)
		{
			scanf(" %d %d %d", &a, &b, &w);
			--a; --b;
			t_edge.w = w;
			t_edge.dst = b;
			adj[a].push_back(t_edge);
			t_edge.dst = a;
			adj[b].push_back(t_edge);
		}
		queue<int>Q;
		bool inq[1001];
		int dist[1001];
		for(int i = 0; i < n; i++) dist[i] = 2000000000;
		memset(inq, 0, sizeof(inq));
		dist[s] = 0;
		inq[s] = 1; Q.push(s);
		while(!Q.empty())
		{
			int v = Q.front(); Q.pop();
			inq[v] = 0;
			for(int i = adj[v].size() - 1; i >= 0; i--)
			{
				if(dist[v]+adj[v][i].w < dist[adj[v][i].dst])
				{
                    dist[adj[v][i].dst] = dist[v]+adj[v][i].w;
					if(!inq[adj[v][i].dst])
					{
						Q.push(adj[v][i].dst);
						inq[adj[v][i].dst] = 1;
					}
				}
			}
		}
		if(dist[t]<2000000000)
			cout<<dist[t]<<"\n";
		else
			puts("He is very hot");
	}
	return 0;
}
