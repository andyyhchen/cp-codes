#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n, in;
	while(~scanf(" %d", &n))
	{
        priority_queue < long long int, vector < long long int> > Q;

		if(!n)break;
		for(int i = 0; i < n; i++)
		{
		    scanf(" %d", &in);
		    Q.push(-in);
		}
		long long int a, b, ans = 0;
		for(int i = 0; i < n-1; i++)
		{
			a = Q.top(); Q.pop();
			b = Q.top(); Q.pop();
			ans += -(a + b);
			Q.push((a + b));
		}
		printf("%lld\n", ans);
	}

	return 0;
}
