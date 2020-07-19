#include <iostream>
#include <math.h>
#include <stack>
using namespace std;
stack < pair<int,int> > prime;
int main()
{
	int in[1000],i;
	char c;
	while(scanf("%d%c", &in[0], &c) && in[0])
	{
		int x = 1;
		for(i = 1; scanf("%d%c", &in[i], &c)&&c!='\n'; i++);
		for(int j = 0; j < i; j+=2) x *= (int)(pow((double)in[j], (double)in[j+1])+0.0001);
		int t = (int)(sqrt(--x) + 0.00001);
		for(int j = 2; j <= t; j++)
		{
			int count = 0;
			if(x % j == 0 && x)
			{
				while(x % j == 0 && x)
				{
					x /= j;
					count ++;
				}
			}
			if(count) prime.push(make_pair(j,count));
		}
		int k, f;
		k = prime.size()-1;
		while(!prime.empty())
		{
			printf("%d %d ",prime.top().first,prime.top().second);
			prime.pop();
			//if(k--) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
