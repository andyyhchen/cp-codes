#include <iostream>
using namespace std;
long long int p[1000001];
struct breakfirst{
	long long int price, w;
};
breakfirst b[1000001];
bool cmp(breakfirst a, breakfirst b)
{
	return a.w < b.w;
}
int main()
{
	int n, m;
	while(~scanf(" %d", &n))
	{
		for(int i = 0; i < n; i++) scanf(" %I64d", p + i);
		scanf(" %d", &m);
		for(int i = 0; i < m; i++)
		{
			scanf(" %I64d %I64d", &b[i].w, &b[i].price);
		}
		sort(p, p + n);
		sort(b, b + m, cmp);
		long long int ans = 0;
		int j = 0, i;
		for(i = 0; i < n; i++)
		{
			while(j < m&&p[i]>b[j].w) j++;
			if(j == m) break;
			ans += b[j].price;
		}
		if(i != n) puts("Impossible.");
		else printf("%I64d\n", ans);
	}
	return 0;
}
