#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge{
	int src, dst, w;
};
int set[101];
int ww[101][101];
bool adj[101][101];
int sw[101][101];
int t, n, m, a, b, w, mMst, sMst;
vector<edge>Edges;
vector<edge>inTree;
edge t_edge1, t_edge2;
int find(int x){return x==set[x] ?  x : find(set[x]);}
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
void bfs(int src)
{
	queue<int>Q;
	bool visit[101];
	ww[src][src] = 0;
	memset(visit,0,sizeof(visit));
	Q.push(src);
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		visit[v] = 1;
		for(int i = 0; i < n; i++)
		{
			if(adj[v][i]&&!visit[i])
			{
				Q.push(i);
				ww[src][i] = max(ww[src][v], sw[v][i]);
			}
		}
	}
}
int main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		Edges.clear();
		inTree.clear();
		mMst = sMst = 0;
		for(int i = 0; i < n; i++) set[i] = i;
		for(int i = 0; i < n; i++)
		    for(int j = 0; j < n; j++)
		        sw[i][j] = adj[i][j] = false;
		for(int i = 0; i < m; i++)
		{
			scanf(" %d %d %d", &a, &b, &w);
			t_edge1.src = a - 1;
			t_edge1.dst = b - 1;
			t_edge1.w = w;
			Edges.push_back(t_edge1);
		}
		int size = Edges.size();
		sort(Edges.begin(), Edges.end(), cmp);
		for(int i = 0; i < size; i++)
		{
			t_edge1 = Edges[i];
			if(find(t_edge1.src) != find(t_edge1.dst))
			{
				set[find(t_edge1.src)] = find(t_edge1.dst);
				mMst += t_edge1.w;
				inTree.push_back(t_edge1);
				Edges.erase(Edges.begin()+i);
			}
		}
		
		size = inTree.size();
		for(int i = 0; i < size; i++)
		{
			t_edge1 = inTree[i];
			adj[t_edge1.src][t_edge1.dst] = adj[t_edge1.dst][t_edge1.src] = true;
			sw[t_edge1.src][t_edge1.dst] = sw[t_edge1.dst][t_edge1.src] = t_edge1.w;
		}
		for(int i = 0; i < n; i++) bfs(i);
		size = Edges.size();
		int minst = 100000000, tMst = mMst;;
		for(int i = 0; i < size; i++)
			minst = min(tMst+Edges[i].w - ww[Edges[i].src][Edges[i].dst], minst);
		sMst = minst;
		if(sMst == mMst && sMst != 0)printf("Not Unique!\n");
		else printf("%d\n", mMst);
	}
	return 0;
}
