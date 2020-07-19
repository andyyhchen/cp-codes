/*
ID : andypcu2
PROG : barn1
LANG : C++
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
int in[210], a[210];
int main()
{
    freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	int m, s, c;
	
	while(~scanf(" %d %d %d", &m, &s, &c))
	{
		for(int i = 0; i < c; i++)
			scanf(" %d", &in[i]);
		sort(in, in + c);
		int t = in[c-1]-in[0]+1;
		for(int i = 1; i < c; i++) a[i] = in[i] - in[i-1] - 1;
		sort(a+1, a+c, cmp);
		for(int i = 1; i < m; i++)
		    t -= a[i];
		cout<<t<<"\n";
	}
	return 0;
}
