#include <iostream>

using namespace std;

int PT[50] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0};


/*int prime(void)
{
	for(int i = 0; i < 50; i++) PT[i] = 1;
	PT[0] = PT[1] = 0;
	for(int i = 2; i <= 7; i++)
	{
		for(int j = 2; j < 50; j++)
			if(!(j % i) && (j ^ i)) PT[j] = 0;
	}
}*/

int visit[17], tmp[17], n, f;

void dfs(int i, int depth)
{
	if(!visit[i])
	{
		tmp[depth] = i;
		if(depth > 0 && !PT[tmp[(depth - 1) % n] + tmp[depth % n]]) return;
		if(depth == n - 1)
		{
			for(int i = 0; i < n ; i++)
			{
				if(!PT[tmp[i] + tmp[(i + 1) % n]]) return;
			}
			if(f++)printf("\n");
			for(int i = 0; i < n; i++)
			{
				printf("%d", tmp[i]);
				if(i != n - 1) printf(" ");
			}
		}
		visit[i] = 1;
		for(int j = 1; j <= n; j++)
			dfs(j, depth+1);
		visit[i] = 0;
	}
}
int main()
{
	int t = 1;
	//prime();
	while(~scanf(" %d", &n))
	{
		f = 0;
        //memset(visit, 0, sizeof(visit));
        printf("\nCase %d:\n",t++);
		dfs(1, 0);
	}
	return 0;
}
