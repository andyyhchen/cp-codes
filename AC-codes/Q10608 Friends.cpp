#include <iostream>
#define Max 30000

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

int SubGroupNum(int n, int *Group)
{
	int ans = 0;
	for(int i = 0; i < Max; i++)
	    if(Group[i] == n) ans++;
	return ans;
}

int main()
{
	int Group[Max], m, n, a, b, max, tmp, t;
	while(~scanf(" %d", &t))
	{
		while(t--)
		{
			while(~scanf(" %d %d", &n, &m))
			{
				max = 0;
				Initial(Group);
				while(m--)
				{
					scanf(" %d %d", &a, &b);
					Union(a, b, Group);
				}
				for(int i = 0; i < Max; i++)
				{
					tmp = SubGroupNum(i, Group);
					if(tmp > max) max = tmp;
				}
				printf("%d\n", max);
			}
		}
	}
	return 0;
}
