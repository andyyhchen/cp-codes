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

int Find(int p, int *Group)
{
	return Group[p];
}

bool IsSameGroup(int a, int b, int *Group)
{
	if(Group[a] == Group[b]) return true;
	return false;
}

int GroupNum(int *Group)
{
	int num = 0;
	for(int i = 0; i < Max; i++)
	{
		for(int j = 0; j < Max; j++)
		{
			if(Group[j] == i)
			{
				num++;
				break;
			}
		}
	}
	return num;
}

int SubGroupNum(int n, int *Group)
{
	int ans = 0;
	for(int i = 0; i < Max; i++)
	    if(Group[i] == n) ans++;
	return ans;
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
