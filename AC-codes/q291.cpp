#include <iostream>

using namespace std;

int tmp[9];
int map[6][6]= {{0, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 0, 1},
                {0, 1, 0, 1, 0, 1},
                {0, 1, 1, 0, 1, 1},
                {0, 0, 0, 1, 0, 1},
                {0, 1, 1, 1, 1, 0}};
void dfs(int v, int depth)
{
    tmp[depth] = v;
	if(depth == 8)
	{
		for(int i = 0; i <= 8; i++)
			printf("%d", tmp[i]);
		printf("\n");
		return;
	}
	for(int i = 1; i < 6; i++)
	{
		if(map[v][i] && map[i][v])
		{
		    map[i][v] = map[v][i] = 0;
			dfs(i, depth+1);
			map[i][v] = map[v][i] = 1;
		}
	}
}
int main()
{
	dfs(1, 0);
}
