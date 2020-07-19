#include <iostream>
#include <vector>
using namespace std;
struct edge{
	int src, dst, w;
};
int main()
{
	int n, m, a, b, c, t = 0;
 	char name[25][15];
 	edge t_edge1, t_edge2;
 	vector<edge> Edges;
	while(cin>>n>>m&&n)
	{
		Edges.clear();
		for(int i = 0; i < n; i++)
			scanf(" %s", name[i]);
		for(int i = 0; i < m; i++)
		{
			cin>>a>>b>>c;
			t_edge2.dst = t_edge1.src = a - 1;
			t_edge2.src = t_edge1.dst = b - 1;
			t_edge2.w = t_edge1.w = c;
			Edges.push_back(t_edge1);
			Edges.push_back(t_edge2);
		}
		int ans[25] = {0}, dist[25];
		for(int i = 0; i < n; i++)
		{
            for(int k = 0; k < 25; k++) dist[k] = 100000000;
            dist[i] = 0;
            for(int j = 0; j < n - 1; j++)
                for(int k = Edges.size() - 1; k >= 0; k--)
                    dist[Edges[k].dst] = min(dist[Edges[k].dst],dist[Edges[k].src]+Edges[k].w);
			for(int j = 0; j < n; j++)
				ans[i] += dist[j];
		}
		int smallest = 2147483647;
		for(int i = 0; i < n; i++)
            smallest = min(smallest, ans[i]);
        for(int i = 0; i < n; i++)
            if(ans[i]==smallest)
            {
				printf("Case #%d : %s\n", ++t, name[i]);
				break;
			}
	}

	return 0;
}
