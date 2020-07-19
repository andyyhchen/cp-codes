#include <iostream>

using namespace std;

int main()
{
	int p,t,a,b,c,ans=0;
	while(~scanf(" %d",&t))
		while(t--&&scanf(" %d",&p)&&!(ans=0))
		{
   			while(p--&&scanf(" %d %d %d",&a,&b,&c))ans+=a*c;
			printf("%d\n",ans);
		}
	return 0;
}
