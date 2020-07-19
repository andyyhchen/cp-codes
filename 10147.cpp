#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct  edge{
	int src, dst, w;
} edge;
bool operator<(const edge a, const edge b)
{
	return a.w>b.w;
}
bool exist[760][760];
int N, point[800][2], M;
vector<edge> E;
int prim()
{
	priority_queue<edge> Q;
	int cost = 0;
	bool T[760] = {false};
	edge t_edge = {0,0,0}, t;
	Q.push(t_edge);
	while(!Q.empty())
	{
		t_edge = Q.top(); Q.pop();
		if(T[t_edge.dst]) continue;
		if(t_edge.w) E.push_back(t_edge);
		T[t_edge.dst] = true;
		cost+=t_edge.w;
		for(int i = 0; i < N; i++)
		{
			if(exist[t_edge.dst][i])
			{
				t.w = 0;
				t.dst = i;
				t.src = t_edge.dst;
				Q.push(t);
			}
			else
			{
				int x = point[t_edge.dst][0]-point[i][0];
				int y = point[t_edge.dst][1]-point[i][1];
				t.w = x*x + y*y;
				t.dst = i;
				t.src = t_edge.dst;
				Q.push(t);
			}
		}
	}
	return cost;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t-- && scanf("%d", &N))
	{
        memset(exist, false, sizeof(exist));
        E.clear();
		for(int i = 0; i < N; i++)
		    scanf(" %d %d", &point[i][0], &point[i][1]);
		scanf(" %d", &M);
		int a, b;
		for(int i = 0; i < M; i++)
		{
			scanf("%d%d", &a, &b);
			exist[a-1][b-1] = exist[b-1][a-1] = true;
		}
		int c = prim();
		if(c)
		{
			int s = E.size();
			for(int i = 0; i < s; i++)
			printf("%d %d\n", E[i].dst+1, E[i].src+1);
		}
		else
		{
                printf("No new highways need\n");
		}
		if(t!=0) printf("\n");
	}
	
}
