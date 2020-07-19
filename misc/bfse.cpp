#include <iostream>
#include <queue>
#define Max 10

using namespace std;


int adj[Max][Max], visit[Max];
queue <int> vertex;

void bfs(int v)
{
	vertex.push(v);
	visit[v] = 1;
	while(!vertex.empty())
	{
		v = vertex.front(); vertex.pop();
		
		printf("%d ", v);
		
		for(int i = 0; i < Max; i++)
		{
			if(adj[v][i] && !visit[i])
			{
				vertex.push(i);
				visit[i] = visit[v] + 1;
			}
		}
	}
}

int main()
{
	int t;
	while(~scanf(" %d", &t))
	{

		for(int i = 0; i < Max; i++)
		{
			for(int j = 0; j < Max; j++)
			{
				adj[i][j] = 0;
			}
			visit[i] = 0;
		}
		
		int x, y;
		for(int i = 0; i < t; i++)
		{
			scanf(" %d %d", &x, &y);
			adj[x][y] = adj[y][x] = 1;
		}
		
		for(int i = 0; i < Max; i++)
		{
			if(!visit[i]) bfs(i);
		}
		
		cout << "\n";
		
		for(int i = 0; i < Max; i++)
		{
		    printf("%d ", visit[i]);
		}
		
		cout << "\n";
		
	}

	system("pause");
	return 0;
}
