#include <stdio.h>
#define max(x,y) (x) > (y) ? (x) : (y)
int map[101][101], path[101][101];
const int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int dfs(int, int);
int r, c;
int main()
{
	int t,i,j,m;
	char name[100];
	scanf(" %d", &t);
	while(t--&&scanf(" %s", name))
	{
		scanf(" %d %d", &r, &c);
		m = 0;
		for(i = 0; i < r; i++)
		    for(j = 0; j < c; j++)
		    {
		        scanf(" %d", &map[i][j]);
		        path[i][j] = -1;
			}
		for(i = 0; i < r; i++)
		    for(j = 0; j < c; j++)
		    {
    			if(path[i][j]<0)path[i][j] = dfs(i,j);
				m = max(m,path[i][j]);
			}
		printf("%s: %d\n", name, m + 1);
	}
	return 0;
}
int dfs(int x, int y)
{
	int i;
	if(path[x][y]>=0) return path[x][y];
	for(i = 0; i < 4; i++)
		if(x+dx[i]<r&&x+dx[i]>=0&&y+dy[i]<c&&y+dy[i]>=0&&map[x+dx[i]][y+dy[i]]>map[x][y])
			path[x][y] = max(dfs(x+dx[i], y+dy[i])+1, path[x][y]);
	return max(path[x][y],0);
}
