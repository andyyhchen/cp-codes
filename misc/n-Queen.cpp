#include <iostream>
#define Max 10
using namespace std;

int D1[Max * 2 + 1], D2[Max * 2 + 1], D3[Max], tmp[Max];

void dfs(int depth, int v)
{
 	tmp[depth] = v;
 	if(depth == Max - 1)
 	{
		for(int i = 0; i < Max; i++)
		{
			printf("%d ", tmp[i]);
		}
		printf("\n");
		return;
	}
 	D1[depth + v] = D2[depth - v + Max] = D3[v] = 1;
 	for(int i = 0; i < Max; i++)
 	{
		if(!D1[depth + i + 1] && !D2[depth - i + Max + 1] && !D3[i])
		{
			dfs(depth+1, i);
		}
	}
	D1[depth + v] = D2[depth - v + Max] = D3[v] = 0;
}

int main()
{
	for(int i = 0; i < Max; i++)
	{
		dfs(0,i);
	}

	system("pause");
	return 0;
}
