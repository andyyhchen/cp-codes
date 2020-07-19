#include <iostream>
#include <vector>
using namespace std;
vector <int> adj[10001];
vector <int> Q[10001];
int anc[10001], visit[10001], set[10001];
int find(int a)
{
	int t = a, p = a;
	while(a!=set[a]) a = set[a];
	while(t!=set[t])
	{
		p = t;
		t = set[t];
		set[p] = a;
	}
	return a;
}
void unionset(int a, int b)
{
	int ga = find(a), gb = find(b);
	set[ga] = gb;
}
void lca(int v)
{
	set[v] = v;
	anc[v] = v;
	for(int i = adj[v].size() - 1; i >= 0; i--)
	{
		lca(adj[v][i]);
		unionset(v,adj[v][i]);
		anc[find(v)] = v;
	}
	visit[v] = 1;
 	for(int i = Q[v].size() - 1; i >= 0; i--)
	    if(visit[Q[v][i]])
	    {
			cout<<anc[find(Q[v][i])]+1<<"\n";
			return;
		}
}
int main()
{
	int n, t, indgree[10001];
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i = 0; i < n; i++)
		{
			indgree[i] = 0;
			visit[i] = 0;
			anc[i] = 0;
			set[i] = 0;
			adj[i].clear();
			Q[i].clear();
		}
		int a, b;
		for(int i = 1; i < n; i++)
		{
			cin>>a>>b;
			adj[a-1].push_back(b-1);
			indgree[b-1]++;
		}
		int root;
		for(root = 0; root < n; root++)
		    if(!indgree[root]) break;
		cin>>a>>b;
		Q[a-1].push_back(b-1);
		Q[b-1].push_back(a-1);
		lca(root);
	}

	return 0;
}
