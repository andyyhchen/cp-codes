#include <iostream>
#include <vector>
using namespace std;
bool adj[101][101];
int color[101], k, n, a, b, maxc, tmp[101];
void dfs(int depth)
{
	if(depth==n)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			    if(adj[i][j]&&color[i]==color[j]) cout<<i<<" "<<j<<"\n";
		int bc = 0;
		for(int i = 0; i < n; i++) cout<<color[i]<<" ";
		cout<<"\n";
		    //if(color[i]) bc++;
		if(bc>maxc)
		{
			maxc = bc;
			for(int i = 0; i < n; i++) tmp[i] = color[i];
		}
		return;
	}
	for(int i = 0; i < 2; i++)
	{
		color[depth] = i;
		dfs(depth+1);
	}
}

int main()
{
	while(cin>>n>>k)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			    adj[i][j] = false;
		maxc = 0;
		while(k--)
		{
			cin>>a>>b;
			adj[a-1][b-1] = adj[b-1][a-1] = true;
		}
		dfs(0);
		for(int i = 0; i < n; i++)
			if(tmp[i]) cout<<i+1<<" ";
		cout<<"\n";
		
	}

	return 0;
}
