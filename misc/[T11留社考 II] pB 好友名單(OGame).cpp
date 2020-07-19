#include <iostream>
#include <stdio.h>
#define Max 1010

using namespace std;

void Initial(int *Group)
{
	int i;
	for(i = 0; i < Max; i++) Group[i] = i;
}

void Union(int a, int b, int *Group)
{
	int x = Group[a], y = Group[b];
	if(Group[a] == Group[b]) return;
	for(int i = 0; i < Max; i++)
		if(Group[i] == y) Group[i] = x;
}
int SameGroupNum(int p, int *Group)
{
	int a = Group[p], ans = 0;
	for(int i = 0; i < Max; i++)
	    if(Group[i] == a) ans++;
	return ans;
}

int main()
{
	int Group[Max], m, n, a, b;
	while(~scanf(" %d %d", &n, &m))
	{
		Initial(Group);
		while(m--)
		{
			scanf(" %d %d", &a, &b);
			Union(a, b, Group);
		}
		printf("%d\n", SameGroupNum(1, Group));
	}
	return 0;
}
