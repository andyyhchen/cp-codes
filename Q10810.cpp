#include <iostream>
#define Max 500010

using namespace std;

int La[Max],Ra[Max];
unsigned long long int ans=0;

void merge(int L, int M, int R)
{
	memcpy(Ra+L,La+L,4*(R-L+1));
	int i=L,j=M+1,k=L;
	unsigned long long int d=0;
	while(i<=M&&j<=R)
	{
		if(Ra[i]<=Ra[j])La[k++]=Ra[i++],ans+=d;
		else La[k++]=Ra[j++],d++;
	}
	while(i<=M) La[k++]=Ra[i++],ans+=d;
	while(j<=R) La[k++]=Ra[j++];
}

void mergesort(int s,int e)
{
	if(s<e)
	{
		mergesort(s,(s+e)/2);
		mergesort((s+e)/2+1,e);
	}
	merge(s,(s+e)/2,e);
}

int main()
{
	int n, count = 1;
	while(~scanf(" %d",&n)&&n)
	{
		for(int i=0;i<n;i++)
			scanf(" %d",&La[i]);
		ans=0;  
		mergesort(0,n-1);
		printf("Case #%d: %llu\n", count++, ans);

	}
	return 0;
}
