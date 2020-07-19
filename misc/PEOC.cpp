#include <iostream>
#define Max 100010

using namespace std;

long long int T[Max];

void build(void)
{
	T[0] = T[1] = 1;
	for(int i = 2; i < Max; i++)
		T[i] = (T[i-1] % 1000000000 + T[i-2] % 1000000000) % 1000000000;
}

int main()
{
	int t;
	build();
	while(~scanf(" %d", &t))
	{
		int n;
		while(t--)
		{
			scanf(" %d", &n);
			cout << T[n] << "\n";
		}
	}
	return 0;
}
