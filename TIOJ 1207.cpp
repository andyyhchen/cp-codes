#include <iostream>
#define fabs(a) (a) < 0 ? -(a) : (a)

using namespace std;

int main()
{
	double curr, prev, mid, in;
	while(~scanf(" %lf", &in))
	{
		prev = 0.0f; curr = in;
		while(fabs(curr - prev) > 1e-50)
		{
			printf("%.50f\n",mid);
            mid = (curr + prev) / 2;
            if(fabs(mid * mid == in))break;
			if(mid * mid < curr) prev = mid * mid;
			else curr = mid * mid;
		}
		printf("%.50f\n", mid);
	}
	return 0;
}
