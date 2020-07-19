#include <iostream>

using namespace std;

int main()
{
	int x,k,t;
	while(~scanf(" %d",&t))
		while(scanf(" %d %d",&x,&k)&&t--)
			if(!(x%k)) printf("0 %d\n",k);
			else printf("%d %d\n",-x,x);
	return 0;
}
