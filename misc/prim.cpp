#include <iostream>
#define Max 3
using namespace std;

int adj[Max][Max];

void prim(int v)
{
	int T[Max], W[Max], w = 0;
	for(int i = 0; i < Max; i++)
	{
		T[i] = 1;W[i] = -1;
	}
	T[v] = 0;
	W[v] = -1;
	for(int k = 0; k < Max - 1; k++)
	{
		for(int i = 0; i < Max; i++)
		{
			if(adj[v][i] && T[i])
			{
				if(W[i] == -1)
				{
					W[i] = adj[v][i];
				}
				if(adj[v][i] < W[i])
				{
					W[i] = adj[v][i];
				}
			}
		}
		int min = 1000000;
		for(int i = 0; i < Max; i++)
		{
			if(~W[i] && W[i] < min)
			{
				min = W[i];
				v = i;
			}
		}
		w += W[v];
		W[v] = -1;
		T[v] = 0;
		
	}
}

int main()
{
	int x, y, w;
	for(int i = 0; i < Max; i++)
	{
		scanf(" %d %d %d", &x, &y, &w);
		adj[x][y] = adj[y][x] = w;
	}
	prim(0);

	system("pause");
	return 0;
}
