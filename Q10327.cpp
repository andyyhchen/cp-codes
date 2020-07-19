#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int N, in[1010];
	while(~scanf(" %d", &N))
	{
		for(int i = 0; i < N; i++) scanf(" %d", &in[i]);
		int k = 0;
		for(int i = N - 1 ; i > 0; i--)
		{
			for(int j = 0; j < i; j++)
			{
				if(in[j] > in[j+1])
				{
					swap(in[j],in[j+1]);
					k++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n", k);
	}
	return 0;
}
