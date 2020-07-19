#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
int CM[20000*20000+1];

int main()
{
	int p[20001], n, k, c;
	while(scanf("%d %d", &n, &k) && n)
	{
		p[0] = c = 0;
		for(int i = 1; i <= n; i++) 
		{
			scanf("%d", &p[i]);
			p[i] = p[i - 1] + p[i];
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				CM[c] = p[i]-p[j-1];
				c++;
			}
		}
		sort(CM, CM+c);
	    printf("%d\n", CM[c - k]);
	}
	
}
