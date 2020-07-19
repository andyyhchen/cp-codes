#include <iostream>
#define Max 1001

using namespace std;

int photo[Max][Max];
bool visit[Max][Max];
int m, n;

void floodfill(int i, int j, int color)
{
	visit[i][j] = true;
 	const int dx[4] = {1,-1,0,0};
 	const int dy[4] = {0,0,1,-1};
 	for(int k = 0; k < 4; k++)
		if(i+dx[k]<m&&i+dx[k]>-1&&j+dy[k]<n&&j+dy[k]>-1&&!visit[i+dx[k]][j+dy[k]]&&photo[i+dx[k]][j+dy[k]]==color)
		    floodfill(i+dx[k], j+dy[k], color);
}

int main()
{
	char in[Max];
	while(~scanf(" %d %d", &m, &n) && (m||n))
	{
		int c = 0;
		for(int i = 0; i < m; i++)
		{
			scanf(" %s", in);
			for(int j = 0; j < n; j++)
			{
				photo[i][j] = in[j] - '0';
				visit[i][j] = false;
			}
		}
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(!visit[i][j])
				{
					floodfill(i, j, photo[i][j]);
					c++;
				}
		cout<<c - 1<<"\n";
	}
	return 0;
}
