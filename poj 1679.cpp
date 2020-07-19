#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct edge{
	int src, dst, w;
};
vector <edge> Edges;
vector <int> inTree;
bool inMst[10001];
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int n, m, set[101];
int find(int t)
{
    if(t!=set[t]) set[t]=find(set[t]);
    return set[t];
}
long long int kruskal(int t)
{
	long long int weight = 0;
	sort(Edges.begin(), Edges.end(), cmp);
	for(int i = 0; i < n; i++) set[i] = i;
	int size = Edges.size();
	for(int i = 0; i < size; i++)
	{
		if(!inMst[i] && find(Edges[i].src) != find(Edges[i].dst))
		{
			set[find(Edges[i].src)] = find(Edges[i].dst);
			weight += Edges[i].w;
			if(!t) inTree.push_back(i);
		}
	}
	return weight;
}

int main()
{
	long long int ti, mMst, sMst;
	edge t;
	cin>>ti;
	while(ti--&&cin>>n>>m)
	{
        inTree.clear(); Edges.clear();
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &t.src, &t.dst, &t.w);
			t.src--; t.dst--;
			Edges.push_back(t);
		}
		for(int i = Edges.size(); i >= 0; i--) inMst[i] = false;
		mMst = kruskal(0); sMst = 2147483647;
		int tMst;
		for(int i = inTree.size() - 1; i >= 0; i--)
		{
			inMst[inTree[i]] = 1;
			tMst = kruskal(1);
			if(tMst >= mMst) sMst = min(tMst, sMst);
			inMst[inTree[i]] = 0;
		}
		if(sMst == mMst&&sMst!=0) printf("Not Unique!\n");
		else printf("%d\n",mMst);
	}
	return 0;
}
