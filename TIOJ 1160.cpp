#include <iostream>
#define Max 200000
#define Hash(x) (x) % 199999
using namespace std;
int c[Max], e[Max];
int main()
{
	int A, min = 2147483647, t = 0,count=0;
	memset(c,0,sizeof(c));
	while(~scanf(" %d", &A) && A)
	{
		int key = Hash(A);
		while(e[key]!=A&&e[key])(++key)%=Max;
		if(!e[key]) { e[key]=A;c[key]++;}
  		else c[key]++;
  		count = c[key];
  		if(count > t)
  		{
			t = count;
			min = A;
		}
		if(count==t&&e[key]<min)
			min=e[key];
		printf("%d %d\n",t,min);
	}
	return 0;
}
