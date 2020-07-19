#include <iostream>

using namespace std;

int main()
{
	int k, n, table[127];
	char in[100001];
	while(~scanf(" %d", &n))
	{
		while(n-- && scanf(" %d %s", &k, in))
		{
			memset(table, 0, 127<<2);
			for(int i = 0; i < k; i++)table[in[i]]++;
			int max = 0;
			for(int i = 0; i < 127; i++) if(table[i] > max) max = table[i];
			for(int i = 0; i < 127; i++) if(table[i] == max) printf("%c", i);
			printf("\n");
		}
	}
	return 0;
}
