#include <iostream>
#define Max 101
using namespace std;

bool v[Max], adj[Max][Max], tmp[Max];
int n, m;


void ini()
{
	m = 0;
	for(int i = 0; i < n; i++)
	{
		v[i] = false;
		for(int j = 0; j < n; j++)
			adj[i][j] = false;
	}
}

bool chk()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(adj[i][j])
				if(v[i]==v[j]) return false;
	return true;
}

void dfs(int t)
{
	if(t == n)
	{
		if(chk())
		{
			int c = 0;
			for(int i = 0; i < n; i++) if(v[i]) c++;
			if(c > m)
			{
				memcpy(tmp, v, n);
				m = c;
			}
		}
		return;
	}
	for(int i = 0; i < 2; i++)
	{
		v[t] = i;
		dfs(t + 1);
	}
}

int main()
{
	int t, k;
	while(~scanf(" %d", &t))
	{
		while(t--)
		{
			int a,b;
			scanf(" %d %d", &n, &k);
			ini();
			for(int i = 0; i < k; i++)
			{
				scanf(" %d %d", &a, &b);
				adj[a][b] = adj[b][a] = true;
			}
			dfs(0);
			printf("%d\n", m);
			for(int i = 0; i < n; i++)
				if(v[i]) printf("%d ", i);
			printf("\n");
		}
	}
}
