#include <iostream>
#include <algorithm>
#define Max 10010
using namespace std;

int main()
{
	int N, in[Max];
	while(~scanf(" %d", &N))
	{
		for(int i = 0; i < N; i++) scanf(" %d", in+i);
		sort(in,in+N);
		int k, ans = 0; scanf(" %d",&k);
		for(int i = 0; i < k; i++) ans+=in[i];
		printf("%d\n", ans);
	}
	return 0;
}
