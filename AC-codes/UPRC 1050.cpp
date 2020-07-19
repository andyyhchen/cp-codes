#include <iostream>
#include <algorithm>
#define min(a , b) (a) < (b) ? (a) : (b)

using namespace std;

int main()
{
	int n, in[1001];
	while(~scanf(" %d", &n))
	{
		int i;
		for(i = 0; i < n; i++) scanf(" %d", &in[i]);
		sort(in, in + n);
		if(n % 2) printf("%d\n", in[n/2]);
		else printf("%d\n", min(in[n/2], in[n/2 - 1]));
	}
	return 0;
}
