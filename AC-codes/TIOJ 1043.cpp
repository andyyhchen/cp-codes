#include <iostream>
#define N 101
#define P 10001

using namespace std;
int nN[N];
unsigned long long int nP[P];
int main()
{
	int n, p;
	while(~scanf(" %d %d", &n, &p) && (n||p))
	{
		for(int i = 0; i <= p; i++) nP[i] = 0;
		for(int i = 0; i < n; i++) scanf(" %d", nN + i);
		nP[0] = 1;
		sort(nN, nN + n);
		for(int i = 0; i < n; i++)
			for(int j = nN[i]; j <= p && j - nN[i] >= 0; j++)
				nP[j] += nP[j - nN[i]];
		cout<<nP[p]<<"\n";
	}
	return 0;
}
