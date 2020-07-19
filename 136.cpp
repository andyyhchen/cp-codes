#include <iostream>
using namespace std;
int main()
{
	int n[1510];
	int d[3] = {2, 3, 5} ;
	n[0] = 1;
	int i = 1;
	while(i<1502)
	{
		int m = 2000000000;
		for(int k = 0; k < i; k++)
		{
			for(int j = 0; j < 3; j++)
				if(n[i]<n[k]*d[j]) m = min(m,n[k]*d[j]);
		}
		n[++i] = m;
	}
	printf("The 1500'th ugly number is %d.\n", n[1500]);
	return 0;
}
