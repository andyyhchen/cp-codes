/*
Problem: Q441.cpp
Author: andyisman
Complete time: Sun Jan 17 10:47:03 2010
*/

#include <stdio.h>

int in[13], tmp[7], k;

void dfs(int v, int depth)
{
	if(k - 1 < 5) return;
	tmp[depth] = in[v];
	if(depth == 5)
	{
		for(int i = 0; i < 6; i++) printf("%d ", tmp[i]);
		printf("\n");
		return;
	}
	for(int i = v+1; i < k; i++)
			dfs(i, depth+1);
}

int main()
{
	while(~scanf(" %d", &k))
	{
		if(!k) break;
		for(int i = 0; i < k; i++)
			scanf(" %d", &in[i]);
		for(int i = 0; i < k; i++)
			dfs(i, 0);
	}
	return 0;
}
