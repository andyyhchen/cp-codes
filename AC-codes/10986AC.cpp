#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct list{
	int dst, w;
};
int main()
{
	int c, n, m, s, t, a, b, w, d = 0;
	vector<list>adj[20000];
	list t_l1, t_l2;
	cin>>c;
	while(c--&&cin>>n>>m>>s>>t)
	{
		for(int i = 0; i < n; i++) adj[i].clear();
		for(int i = 0; i < m; i++)
		{
			scanf(" %d %d %d", &a, &b, &w);
			t_l1.dst = a; t_l2.dst = b;
			t_l1.w = t_l2.w = w;
			adj[a].push_back(t_l2);
			adj[b].push_back(t_l1);
		}
		int dist[20000], inq[20000];
		for(int i = 0; i < n; i++)
		{
			dist[i] = 100000000;
			inq[i] = false;
		}
		queue<int>Q; Q.push(s); dist[s] = 0; inq[s] = 1;
		while(!Q.empty())
		{
			int v = Q.front(); Q.pop(); inq[v] = 0;
			for(int i = adj[v].size()-1; i >= 0; i--)
			    if(dist[adj[v][i].dst]>dist[v]+adj[v][i].w)
			    {
                    dist[adj[v][i].dst] = dist[v]+adj[v][i].w;
                    if(!inq[adj[v][i].dst])
                    {
						Q.push(adj[v][i].dst);
						inq[adj[v][i].dst] = 1;
					}
				}
		}
		cout<<"Case #"<<++d<<":"<<" ";
		if(dist[t]!=100000000)
			cout<<dist[t]<<"\n";
		else
		    cout<<"unreachable"<<"\n";
	}
	return 0;
}
