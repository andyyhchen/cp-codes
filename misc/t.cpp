#include <iostream>
#define Max 4

using namespace std;

int adj[Max][Max] = {{0, 1, 1, 0},
					 {1, 0, 0, 0},
					 {1, 0, 0, 0},
					 {0, 0, 0, 0}}, visit[Max];

void dfs(int v)
{
	if(!visit[v])
	{
		visit[v] = 1;
		for(int i = 0; i < Max; i++)
		    if(adj[v][i]) dfs(i);
	}
	return;
}

int main()
{
	int count = 0;
	for(int i = 0; i < Max; i++)
	{
		if(!visit[i])
		{
			count++;
			dfs(i);
		}
	}
	cout << count << "\n";


	system("pause");
	return 0;
}
