#include <iostream>
#define Max 10
using namespace std;

typedef struct vertex{
	int dst,weigh;
	struct vertex *next;
} V;

typedef struct edge{
	int src,dst,weigh;
} Edge;

V *adj_list[Max]={NULL};
Edge E[Max];

void Insert(int src, int dst, int weigh)
{
	V *ptr=(V*)malloc(sizeof(V));
	ptr->dst=dst,ptr->weigh=weigh;
	ptr->next=adj_list[src];
	adj_list[src]=ptr;
}
bool cmp(Edge a, Edge b)
{
	return a.weigh<b.weigh;
}
void CreatEdge()
{
	int n=0;
	for(int i=0;i<Max;i++)
		for(V *j=adj_list[i];j!=NULL;j=j->next,n++)
			E[n].weigh=j->weigh,E[n].src=i,E[n].dst=j->dst;
	sort(E,E+n,cmp);
}
void Kruskal()
{
	int T[Max]={-1},W[Max],n=0,src,dst,num=0;
	for(int i=0;i<Max-1;i++)
	{
		src=E[n].src,dst=E[n++].dst;
		if(!(~T[src])&&!(~T[dst])) T[src]=T[dst]=num++;
		else if(!(~T[src])) T[src]=T[dst];
		else if(!(~T[dst])) T[dst]=T[src];
		else if(T[src]^T[dst])
			for(int j=0;j<Max;j++) if(!(T[j]^T[dst])) T[j]=T[dst];
		else if(!(T[src]^T[dst])) continue;
		W[dst]=E[n-1].weigh;
	}
}

int main()
{

	system("pause");
	return 0;
}
