#include <iostream>

using namespace std;

int main()
{
	int n,count,tmp;
	while(~scanf(" %d",&n)&&n)
	{
		count=0;
		while(n--)
		{
			scanf(" %d",&tmp);
			count+=tmp;
		}
		if(count/2<n)printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}
