#include <iostream>
#define Max 10

using namespace std;

int visit[Max] = {0};
int vertex[Max][Max] ={0, 0};

void dfs(int v, int d)
{
	for(int i = 0; i < Max; i++)
	{
		if(vertex[v][i] && (visit[i] == 0))
		{
			visit[i] = d;
			printf("->%d", i);
			dfs(i, d + 1);
		}
	}
}


int main()
{
	int a, b;
	while(~scanf("%d %d", &a, &b))
	{
		if(!(~a) && !(~b)) break;
		vertex[a][b] = vertex[b][a] = 1;
	}
	for(int i = 0; i <Max; i++)
	{
		dfs(i, 1);
		cout << "\n";
	}

	system("pause");
	return 0;
}
