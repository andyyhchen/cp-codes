#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a,b,c,d;
	const double PI=2.0*acos(0.0);
	while(~scanf(" %lf",&a))
	{
		b=4*(a*a*PI/12-a/2*(sqrt(3)*a/2 - a/2));
		c=2*(a*a*PI/2-a*a)-2*b;
		d=a*a-(c+b);
		printf("%.3f %.3f %.3f\n",b,c,d);
	}
	return 0;
}
