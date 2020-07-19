#include <iostream>
using namespace std;
int a[1000001];
int partition(int l, int r)
{
	int b = l-1, key = a[r];
	for(int i = l; i < r; i++)
		if(a[i]>key) swap(a[++b], a[i]);
	swap(a[++b],a[r]);
	return b;
}
int select(int l, int r, int k)
{
	if(l<=r)
	{
		int t = partition(l,r);
		if(t > k)
	    	return select(l,t-1,k);
		if(t < k)
	    	return select(t+1,r,k);
		if(t == k)
		    return a[k];
	}
}

int main()
{
	int n, k;
	while(cin>>n>>k)
	{
		for(int i = 0 ; i < n; i++) scanf("%d",&a[i]);
		cout<<select(0,n-1,k-1)<<"\n";
	}

	return 0;
}
