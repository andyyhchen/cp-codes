#include <stdio.h>
#include <math.h>
int main()
{
 	int n; double t = log10(2.0);
	while(~scanf(" %d", &n))
 		printf("%d\n",(2 * (n - (int)(pow(2.0, (double)((int)(log10((double)n) / t+ 0.0001))) + 0.0001)) + 1));
	return 0;
}
