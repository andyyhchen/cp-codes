#include <iostream>

using namespace std;

int main()
{
	long long int a, b;
	while(scanf(" %I64d %I64d", &a, &b) && (a||b))
	{
		if(a>b)swap(a,b);
		printf("%I64d\n", a * (a + 1) * (3 * b - a + 1) / 6);
	}
	return 0;
}
