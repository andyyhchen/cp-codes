#include <iostream>
#include <vector>
#include <algorithm>
#define Max 10010

using namespace std;

typedef struct edge{
	int src, dst, weigh;
}Edge;

bool operator<(const Edge &a, const Edge &b)
{
	return a.weigh < b.weigh;
}
int disjointset[Max];
bool T[Max];
int n, m;
vector <Edge> Edges;

bool unionfind(int a, int b)
{
	if(!disjointset[a] && !disjointset[b]) disjointset[a] = disjointset[b] = a;
	else if(!disjointset[a]) disjointset[a] = disjointset[b];
	else if(!disjointset[b]) disjointset[b] = disjointset[a];
	else
	{
		int x = a, y = b;
		while(disjointset[a]!=a) a = disjointset[a];
		while(disjointset[b]!=b) b = disjointset[b];
        while(disjointset[x]!=x)
		{
			int t = x;
			x = disjointset[x];
			disjointset[t] = a;
		}
		while(disjointset[y]!=y)
		{
			int t = y;
			y = disjointset[y];
			disjointset[t] = a;
		}
		if(a==b) return false;
		else disjointset[a]=b;
		return true;
	}
}

long long int kruskal()
{
	long long int w = 0;
	for(int i = 0; i < n+5; i++) disjointset[i] = T[i] = 0;
	int size = Edges.size();
	if(size < n - 1) return -1;
	sort(Edges.begin(),Edges.end());
	for(int i = 0; i < size; i++)
	{
		if(unionfind(Edges[i].src, Edges[i].dst))
		{
			w += Edges[i].weigh;
			T[Edges[i].src] = T[Edges[i].dst] = 1;
		}
	}
	return w;
}

int main()
{
	int i ,j, c;
	while(scanf(" %d %d", &n, &m)&&(n||m))
	{
		Edges.clear();
		Edge t_edge;
		for(int k = 0; k < m; k++)
		{
			scanf(" %d %d %d", &i, &j, &c);
			t_edge.src = i; t_edge.dst = j; t_edge.weigh = c;
			Edges.push_back(t_edge);
		}
		int ans = kruskal();
		bool flag = true;
		for(int a = 1; a <= n; a++)
		{
			if(T[a]==0) flag = false;
		}
		if(!flag) cout<<-1<<"\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
