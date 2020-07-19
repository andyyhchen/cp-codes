#include <iostream>

using namespace std;

int main()
{
	int a, b;
	while(~scanf(" %d %d", &a, &b) && (a||b))
	{
		if(a<b)swap(a,b);
		while((a%=b)&&(b%=a));
		printf("%d\n",a+b);
	}
	return 0;
}
