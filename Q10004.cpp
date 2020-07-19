/*
Problem: Q10004.cpp
Author: andyisman
Complete time: Sat Jan 16 18:12:39 2010
*/

#include <iostream>
#define Max 201
using namespace std;

int n, m;
bool map[Max][Max], flag = false;
int visit[Max];

void ini(void)
{
	flag = false;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			map[i][j] = false;
		}
		visit[i] = 0;
	}
}

void dfs(int depth, int v)
{
	visit[v] = depth;
	if(flag) return;
	for(int i = 0; i < n; i++)
	{
		if(map[v][i])
		{
			if(!visit[i])
			{
				dfs(depth+1, i);
			}
			else
			{
				if(visit[v] % 2 == visit[i] % 2)
				{
					flag = true;
					return;
				}
			}
		}
	}
}


int main()
{
	while(~scanf(" %d", &n))
	{
		if(!n) break;
		ini();
		scanf(" %d", &m);
		int x, y;
		for(int i = 0; i < m; i++)
		{
			scanf(" %d %d", &x, &y);
			map[x][y] = map[y][x] = true;
		}
		for(int i = 0; i < n; i++)
		{
			if(!visit[i]) dfs(1, i);
			if(flag) break;
		}
		if(flag)
		    printf("NOT BICOLORABLE.\n");
		else
		    printf("BICOLORABLE.\n");
	}
	return 0;
}
