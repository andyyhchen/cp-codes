#include <iostream>

using namespace std;

int main()
{
	int T, N, in[50010],dp[50010];
	while(~scanf(" %d", &T))
	{
		while(T--)
		{
			scanf(" %d", &N);
			for(int i = 0; i < N; i++)
				scanf(" %d", &in[i]);
			int min = in[N-1];
			for(int i = N-1; i > 0; i--)
			{
				if(in[i] < min)	min = in[i];
				dp[i] = min;
			}
			int max = in[0], c = 0;
			for(int i = 1; i < N-1; i++)
			{
				if(in[i] > max && in[i] < dp[i+1]) c++;
				if(in[i] > max) max = in[i];
			}
			cout << c << "\n";
				
		
		}
	}
	return 0;
}
