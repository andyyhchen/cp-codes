#include <iostream>
#include <queue>
#include <vector>
#define Max 2010
using namespace std;
struct edge{
	int src, dst, w;
};
vector<edge> Edges;
int main()
{
	edge t_edge;
	int dist[Max/2], a, b, w,n,m,t;
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		Edges.clear();
		for(int i = 0; i < n; i++) dist[i] = 1000000000;
		for(int i = 0; i < m; i++)
		{
			scanf(" %d %d %d", &a, &b, &w);
			t_edge.src = a-1; t_edge.dst = b-1; t_edge.w = w;
			Edges.push_back(t_edge);
		}
		int s = Edges.size();
		dist[Edges[0].src] = 0;
		for(int i = 0; i < n-1; i++)
		    for(int j = 0; j < s; j++)
		        if(dist[Edges[j].src]+Edges[j].w < dist[Edges[j].dst])
		            dist[Edges[j].dst] = dist[Edges[j].src]+Edges[j].w;
		bool flag = true;
		for(int j = 0; j < s; j++)
		    if(dist[Edges[j].src]+Edges[j].w < dist[Edges[j].dst])
		    {
				flag = false;
				break;
			}
		if(!flag) cout<<"possible\n";
		else cout<<"not possible\n";
	}
	return 0;
}
