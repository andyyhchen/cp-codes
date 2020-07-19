#include <stdio.h>
#include <string.h>
int main()
{
	int k, n;
	char in[101], ans[101];
	while(~scanf(" %d %d", &n, &k))
	{
		for(int i = 0; i < n; i++)
		{
			scanf(" %s", in);
			if(i == (n - k))
				memcpy(ans, in, 101);
		}
		printf("%s\n", ans);
	}

	return 0;
}
