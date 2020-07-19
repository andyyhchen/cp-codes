#include <stdio.h>
int main()
{
	long long int ans, a;
	int n;
	while(~scanf("%d", &n))
	{
		ans = 0;
		while(n--) {scanf("%I64d", &a); ans^=a;}
		printf("%I64d\n", ans);
	}
}
