#include <iostream>
#include <queue>
#define Max 100

using namespace std;

queue <int> vi;
//int front = 0, back = 0, queue[Max];
int adj[Max][Max], visit[Max];

/*int empty(void)
{
    if(front - 1 > back) return 1;
    else return 0;
}
int pop(void)
{
	return queue[front--];
}

void push(int in)
{
	queue[back++] = in;
}*/

void bfs(int v)
{
	vi.push(v);
	while(!vi.empty())
	{
		v = vi.front();
		vi.pop();
		
		if(visit[v])
 		{
			visit[v] = 0;
   printf("%d ", v);
			for(int i = 0; i < Max; i++)
			{
				if(adj[v][i] && visit[i]) vi.push(i);
   }
		}
	}
}
int main()
{

	for(int i = 0; i < Max; i++) visit[i] = 1;
	for(int i = 0; i < Max; i++)
	{
		for(int j = 0; j < Max; j++)
		{
			adj[i][j] = 0;
		}
	}
	int x, y;
	for(int j = 0; j < 2; j++)
	{
		scanf(" %d %d", &x, &y);
		adj[x][y] = adj[y][x] = 1;
	}
	//for(int i = 0; i < Max; i++)
	//{
		//front = back = 0;

		bfs(1);
		cout << "\n";
	//}
	system("pause");
	return 0;
}
