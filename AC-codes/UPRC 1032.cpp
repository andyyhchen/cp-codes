#include <iostream>

using namespace std;

int main()
{
	int in[1001];
	while(~scanf(" %d", &in[0]))
	{
		int sum = in[0], i;
		if(!in[0]) break;
		for(i = 1; ; i++)
		{
			scanf(" %d", &in[i]);
			sum += in[i];
			if(!in[i]) break;
		}
		printf("%d %d %d\n", in[0], i, sum);
	}
	return 0;
}
