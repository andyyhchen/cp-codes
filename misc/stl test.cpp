#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[100002], num, i;
	while(~scanf(" %d", &a[0]))
	{
		for(num = 1; ~scanf(" %d",&a[num]); num++);
		sort(a, a + num);
		for(i = num - 1; i >= 0; i--)
		    printf("%d ", a[i]);
	}
    return 0;
}
