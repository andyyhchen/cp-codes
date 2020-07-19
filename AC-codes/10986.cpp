#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge{
	int src, dst, w;
};
int main()
{
	int n, m, s, t, a, b, w, c, d = 0;
	edge t_edge1, t_edge2;
	vector<edge> Edges;
  	cin>>c;
	while(c--&&cin>>n>>m>>s>>t)
	{
		Edges.clear();
		for(int i = 0; i < m; i++)
		{
			scanf(" %d %d %d", &a, &b, &w);
			t_edge1.src = t_edge2.dst = a;
			t_edge1.dst = t_edge2.src = b;
			t_edge1.w = t_edge2.w = w;
			Edges.push_back(t_edge1);
			Edges.push_back(t_edge2);
		}
		int dist[20000];
		for(int i = 0; i < n; i++) dist[i] = 100000000;
		dist[s] = 0;
		for(int i = 0; i < n - 1; i++)
		    for(int j = Edges.size() - 1; j >= 0; j--)
		        dist[Edges[j].dst] = min(dist[Edges[j].src]+Edges[j].w,dist[Edges[j].dst]);
		cout<<"Case #"<<++d<<":"<<" ";
		if(dist[t]!=100000000)
			cout<<dist[t]<<"\n";
		else
		    cout<<"unreachable"<<"\n";
	}
	return 0;
}
