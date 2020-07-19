#include <iostream>

using namespace std;

const int Max = 100;
int adj[Max][Max];
char edge[10][3] = {"AH", "CD", "AB", "CE", "AD", "DE", "DF", "FG", "GH", "AI"};

int main()
{
	memset(adj, 0, sizeof(adj));
	int x, y;
	for(int i = 0; i < 10; i++)
	{
		x = edge[i][0] - 'A'; y = edge[i][1] - 'A';
		adj[x][y] = adj[y][x] = 1;
	}
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		    printf("%d ", adj[i][j]);
		printf("\n");
	}
	

	system("pause");
	return 0;
}
