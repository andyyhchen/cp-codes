#include <iostream>
#include <math.h>
#define f(t) 1/(1/(sqrt(x*x-t*t)) + 1/(sqrt(y*y-t*t)))
using namespace std;
int main()
{
	double x, y, c;
	while(cin>>x>>y>>c)
	{
		double left = 0.0, right = 10000000000.0, mid;
		while(fabs(left - right)>0.000001)
		{
			mid = (left+right)/2;
			if(f(mid)>c) left = mid;
			else right = mid;
		}
		printf("%.3f\n",(left+right)/2);
	}

	return 0;
}
