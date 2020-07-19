#include <iostream>
#define Max 100

using namespace std;

int map[Max][Max], visit[Max][Max];

void flood(int x, int y, int mx, int my, int oc, int nc)
{
	if(x < mx && y < my && x >= 0 && y >= 0)
	{
		if(visit[x][y] && oc == map[x][y])
		{
			map[x][y] = nc;
			visit[x][y] = 0;
			flood(x, y + 1, mx, my, oc, nc);
			flood(x, y - 1, mx, my, oc, nc);
			flood(x + 1, y, mx, my, oc, nc);
			flood(x - 1, y, mx, my, oc, nc);
			flood(x - 1, y - 1, mx, my, oc, nc);
			flood(x + 1, y - 1, mx, my, oc, nc);
			flood(x + 1, y + 1, mx, my, oc, nc);
			flood(x - 1, y + 1, mx, my, oc, nc);
		}
		
	}
	
}

int main()
{
	int m, n;
	while(~scanf(" %d %d", &m, &n))
	{
		if((!m) && (!n)) break;
		
		memset(visit, 1, sizeof(visit));
		
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) scanf(" %c", &map[i][j]);
			
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(map[i][j] == '*') map[i][j] = 0;
				else map[i][j] = 1;
			}
		}
		int ans = 0;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(visit[i][j])
				{
					if(map[i][j] == 1)
					{
						flood(i, j, m, n, 1, 1);
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
