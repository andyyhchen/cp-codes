#include <iostream>
#include <vector>
using namespace std;
struct vertex{
	char name[35];
};
bool operator==(const vertex a, const vertex b)
{
	return !strcmp(a.name, b.name);
}
int main()
{
	int n, r, t = 0, adj[210][210];
	vector <vertex> point;
	vertex t_v1, t_v2;
	while(cin>>n>>r&&(n+r))
	{
		point.clear();
		for(int i = 0; i < n; i++)
		    for(int j = 0; j < n; j++)
		        adj[i][j] = 0;
		int i, j, s, w;
		while(r--)
		{
			scanf(" %s %s %d", t_v1.name, t_v2.name, &w);
			s = point.size();
			for(i = 0; i < s; i++)
			    if(point[i]==t_v1) break;
			if(i == s) point.push_back(t_v1);
			s = point.size();
			for(j = 0; j < s; j++)
				if(point[j]==t_v2) break;
			if(j == s) point.push_back(t_v2);
			adj[i][j] = adj[j][i] = w;
 		}
 		scanf(" %s %s", t_v1.name, t_v2.name);
 		s = point.size();
 		for(int i = 0; i < s; i++)
 		    for(int j = 0; j < s; j++)
 		        for(int k = 0; k < s; k++)
 		            adj[j][k] = max(adj[j][k],min(adj[j][i],adj[i][k]));
 		for(i = 0; i < s; i++)
			if(point[i]==t_v1) break;
		for(j = 0; j < s; j++)
			if(point[j]==t_v2) break;
		cout<<"Scenario #"<<++t<<"\n"<<adj[i][j]<<" tons"<<"\n\n";
	}
	return 0;
}
