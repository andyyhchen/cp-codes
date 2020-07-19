#include <iostream>
#include <math.h>
using namespace std;
int p, q ,r ,s ,t ,u;
double f(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2.0) + u;
}
int main()
{
    //freopen("out.txt","w",stdout);
	while(cin>>p>>q>>r>>s>>t>>u)
	{
		double left = 0.0, right = 1.0, mid;
		if(f(left)*f(right)>0.0)
            printf("No solution\n");
		else
		{
			while(fabs(left - right)<0.00001)
			{
				mid = (left + right) / 2;
				if(f(mid) < 0) right = mid;
				else left = mid;
			}
			if((left+right)/2.0<=1.0&&(left+right)/2.0>=0.0)
				printf("%.4f\n",(left+right)/2.0+10e-9);
		}
	}

	return 0;
}
