#include <iostream>
#define Max 100
using namespace std;

int disjoint[Max];

void ini()
{
	for(int i=0;i<Max;i++)disjoint[i]=i;
}

int findset(int x)
{
	int p=x;
	while(p!=disjoint[p])p=disjoint[p];
	while(x!=disjoint[x])
	{
		x=disjoint[x];
		disjoint[x]=p;
	}
	return p;
}

int disjoint_union(int a,int b)
{
	int x=findset(a);
	int y=findset(b);
	disjoint[x]=disjoint[y];
}
int main()
{
	ini();
	for(int i=1;i<6;i++)
		disjoint_union(i-1,i);
	cout<<findset(4);

	system("pause");
	return 0;
}
