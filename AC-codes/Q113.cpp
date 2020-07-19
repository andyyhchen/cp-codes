#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double p,n,k;
	while(~scanf(" %lf %lf",&n,&p))
		printf("%.0f\n",pow(p,1/n));
	return 0;
}
