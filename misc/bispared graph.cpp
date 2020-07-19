#include <iostream>
#define Max 3
using namespace std;

int adj[Max][Max] = {{0,1,0},
					 {1,0,1},
					 {0,1,0}}, visit[Max];

void dfs(int depth, int v)
{
	if(!visit[v])
	{
		visit[v] = depth;
		for(int i = 0; i < Max; i++)
		{
			if(adj[v][i])
			{
				dfs(depth + 1, i);
			}
		}
	}
}

int chk(int v)
{
	for(int i = 0; i < Max; i++)
	{
		if(adj[v][i] && (v ^ i))
		{
			if(visit[v] % 2 == visit[i] % 2) return 0;
		}
	}
	return 1;
}

int main()
{
	for(int i = 0; i < Max; i++)
	{
		visit[i] = 0;
	}
	for(int i = 0; i < Max; i++)
	{
		dfs(1, i);
	}
	for(int i = 0; i < Max; i++)
	{
		cout << chk(i) << "\n";
	}
	system("pause");
	return 0;
}
