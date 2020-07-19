#include <stdio.h>
#define Max 21

char map[Max][Max];

void flood(int y, int x)
{
	const char a[4] = {'U', 'D', 'L', 'R'};
	const int dy[4] = {-1, 1, 0, 0};
	const int dx[4] = {0, 0, -1, 1};
	for(int i = 0; i < 4; i++)
	{
		if(map[y + dy[i]][x + dx[i]] == '.' || map[y + dy[i]][x + dx[i]] == 'T' )
		{
			printf("%c", a[i]);
			map[y][x] = '#';
			flood(y + dy[i], x + dx[i]);
			return;
		}
	}

}
int main()
{
	int t, N, M, sx, sy;;
	while(~scanf(" %d", &t))
	{
		while(t--)
		{
			scanf(" %d %d", &N, &M);
			for(int i = 0; i < N; i++)
			{
				for(int j = 0; j < M; j++)
				{
					scanf(" %c", &map[i][j]);
					if(map[i][j] == 'S')
					{
					    sy = i; sx = j;
					}
				}
			}
			flood(sy, sx);
			printf("\n");
		}
	}
	return 0;
}
