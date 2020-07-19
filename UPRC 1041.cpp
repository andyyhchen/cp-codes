#include <iostream>

using namespace std;

int main()
{
	int N;
	unsigned long long int in[3];
	while(~scanf(" %d", &N))
	{
		for(int i = 0; i < N;i++)
		{
			scanf(" %I64u %I64u %I64u", &in[0], &in[1], &in[2]);
			sort(in, in+3);
			if(in[0] >= in[2] || in[1] >= in[2] || in[0] * in[0] >= in[2] * in[2] || in[1] * in[1] >= in[2] * in[2] || in[0] * in[0] + in[1]*in[1] > in[2] *in[2] || in[0] * in[0] + in[1]*in[1] < in[2] *in[2])
				printf("no\n");
			if(in[0] * in[0] + in[1]*in[1] == in[2] *in[2])
			    printf("yes\n");
		}
	}
	return 0;
}
