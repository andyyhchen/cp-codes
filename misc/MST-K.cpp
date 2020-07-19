#include <iostream>

using namespace std;

typedef struct e{
	int e[2];
	int weigh;
	int s;
} edge;

edge E[10];
int v[8] = {-1};

int cmp(edge a, edge b)
{
	if(a.weigh < b.weigh)return 1;
	else return 0;
}
int main()
{
	for(int i = 0; i < 7; i++)
	{
		scanf(" %d %d %d", &E[i].e[0], &E[i].e[1], &E[i].weigh);
		E[i].s = 0;
	}
	for(int i = 0; i < 8; i++)
	    v[i] = -1;
	sort(E, E + 7, cmp);
	int n = 0;
	for(int i = 0; i < 7; i++)
	{
		int v1 = E[i].e[0], v2 = E[i].e[1];
		E[i].s = 1;
		if(!(~v[v1]) && !(~v[v2]))
		{
			v[v1] = v[v2] = n++;
		}
		else if(!(~v[v1]))
		{
			v[v1] = v[v2];
		}
		else if(!(~v[v2]))
		{
			v[v2] = v[v1];
		}
		else if(v[v1] != v[v2])
		{
			for(int i = 0; i < 7; i++)
			{
				if(v[i] == v[v1])
				    v[i] = v[v2];
			}
		}
		else if(v[v1] == v[v2])
		{
			E[i].s = 0;	continue;
		}
		
	}
	for(int j = 0; j < 7; j++)
	{
		if(E[j].s)
		{
			printf("%d ", E[j].weigh);
		}
	}
	system("pause");
	return 0;
}
