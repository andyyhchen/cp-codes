#include <iostream>
#include <vector>
#include <algorithm>
#define Max 100001

using namespace std;

typedef struct edge{
	int src,dst,weigh;
}Edge;

typedef struct vertex{
	int x,y;
}Ver;

bool operator<(const Edge &a,const Edge &b)
{
		return a.weigh<b.weigh;
}

bool cmpx(Ver a,Ver b)
{
	return a.x<b.x;
}

bool cmpy(Ver a,Ver b)
{
	return a.y<b.y;
}

vector <Edge> Edges;
int n,num=0,disjointset[Max];
Ver point[Max],point2[Max];
bool iscycle(int a,int b)
{
	int x=a,y=b;
	while(a!=disjointset[a])a=disjointset[a];
	while(b!=disjointset[b])b=disjointset[b];
	while(x!=disjointset[x])
	{
		int t = x;
		x = disjointset[x];
		disjointset[t] = a;
	}
	while(y!=disjointset[y])
	{
		int t = y;
		y = disjointset[y];
		disjointset[t] = a;
	}
	if(a==b)return true;
	else
	{
		disjointset[b]=a;
		return false;
	}
}

bool disjoint(int a, int b)
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
			w=num=0;Edges.clear();
			for(int i=0; i<n; i++)
			{
			    scanf(" %d %d",&point[i].x,&point[i].y),disjointset[i]=0;
				point[i].x;point[i].y;
			}
			sort(point,point+n,cmpx);
			for(int i=0;i<n-1;i++)
			{
				if(point[i].x==point[i+1].x)
				{
					t_edge.src=i;t_edge.dst=i+1;t_edge.weigh=abs(point[i].y-point[i+1].y);
					Edges.push_back(t_edge);
				}
			}
			sort(point,point+n,cmpy);
   			for(int i=0;i<n-1;i++)
			{
				if(point[i].y==point[i+1].y)
				{
					t_edge.src=i;t_edge.dst=i+1;t_edge.weigh=abs(point[i].x-point[i+1].x);
					Edges.push_back(t_edge);
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
