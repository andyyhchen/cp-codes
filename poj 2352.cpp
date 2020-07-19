#include <iostream>
using namespace std;
const int Max = 32002;
int a[32002], level[15001];
void insert(int x)
{
	for(int i = x; i < Max; i+=i&(-i)) a[i]++;
}
int sum(int x)
{
	int t = 0;
	for(int i = x; i > 0; i-=i&(-i)) t+=a[i];
	return t;
}
int main()
{
	int x, y, n, t;
	cin>>n;
	memset(a,0,sizeof(a));
	memset(level,0,sizeof(level));
	t = n;
	while(t--)
	{
		scanf(" %d %d", &x, &y);
		level[sum(x+1)]++;
		insert(x+1);
	}
	for(int i = 0; i < n; i++) printf("%d\n",level[i]);
	return 0;
}
