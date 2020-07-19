#include <iostream>

using namespace std;

int main()
{
	int a,b,c,d;
	while(scanf(" %d %d %d %d",&a,&b,&c,&d)&&(a||b||c||d))
	{
		int degree=1080;
		(a-b>0)?degree+=(a-b)*9:degree+=(40+a-b)*9;
		(c-b>0)?degree+=(c-b)*9:degree+=(40+c-b)*9;
		(c-d>0)?degree+=(c-d)*9:degree+=(40+c-d)*9;
		printf("%d\n",degree);
	}
	return 0;
}
