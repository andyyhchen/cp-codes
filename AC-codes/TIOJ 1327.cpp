#include <iostream>
#include <vector>
#include <algorithm>
#define Max 100001

using namespace std;

typedef struct edge{
	int src,dst,weigh;
}Edge;

bool operator<(const Edge &a,const Edge &b)
{
		return a.weigh<b.weigh;
}

vector <Edge> Edges;
int point[Max][2],n,num=0,disjointset[Max];

inline bool iscycle(int a,int b)
{
	int x=a,y=b;
	while(a!=disjointset[a])a=disjointset[a];
	while(b!=disjointset[b])b=disjointset[b];
	while(x!=disjointset[x])
	{
		x=disjointset[x];
		disjointset[x]=a;
	}
	while(y!=disjointset[y])
	{
		y=disjointset[y];
		disjointset[y]=a;
	}
	if(a==b)return true;
	else
	{
		disjointset[b]=a;
		return false;
	}
}

inline bool disjoint(int a, int b)
{
	if(!disjointset[a]&&!disjointset[b])
	{
		disjointset[a]=a;
		disjointset[b]=a;
	}
	else if(!disjointset[a])disjointset[a]=disjointset[b];
	else if(!disjointset[b])disjointset[b]=disjointset[a];
	else if(iscycle(a,b)) return false;
	return true;
}

int main()
{
	int t;long long int w;
	Edge t_edge;
	while(~scanf(" %d",&t))
	{
		while(t--)
		{
			scanf(" %d",&n);
			w=num=0;while(!Edges.empty())Edges.pop_back();
			for(int i=0; i<n; i++)
			{
			    scanf(" %d %d",&point[i][0],&point[i][1]),disjointset[i]=0;
			    for(int j=0; j<i;j++)
			    {
					if(point[j][0]==point[i][0]||point[j][1]==point[i][1])
					{
						t_edge.src=i,t_edge.dst=j,t_edge.weigh=abs(point[j][0]-point[i][0]+point[j][1]-point[i][1]);
						Edges.push_back(t_edge);
					}
				}
			}
			int m=Edges.size();
			if(m<n-1)
			{
				printf("0\n");
				continue;
			}
			sort(Edges.begin(),Edges.end());
			for(int i=0;i<m;i++)
			{
				if(disjoint(Edges[i].src,Edges[i].dst))
				{
					w+=(long long int)Edges[i].weigh;
				}
			}
			printf("%I64d\n",w);
		}
	}

}
