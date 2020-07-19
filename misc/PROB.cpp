#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int T, N; long long int h[1010];

	while(~scanf(" %d", &T))
	{
	    while(T--)
	    {
			scanf(" %d", &N);
			for(int i = 0; i < N; i++) scanf(" %I64d", &h[i]);
			long long int c = 0;
			for(int i = N - 1; i > 0; i--)
			{
				for(int j = 0; j < i; j++)
				{
					if(h[j] > h[j+1])
					{
						swap(h[j], h[j+1]);
						c++;
					}
				}
			}
			long long int ans = 0;
			ans = h[N-1] - h[0];

			printf("%I64d\n%I64d\n", ans, c);
		}
	}
	return 0;
}
