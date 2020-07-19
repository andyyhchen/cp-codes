#include <iostream>
using namespace std;
unsigned int prime[15625001];
inline void make_p()
{
	register unsigned int i, j, k;
	#define f(x) ((prime[((x)>>5)]>>((x)&31))&1)
	for(i = 1; i < 15815; i++)
		if(f(i)==0)
			for(j = (i*(i+1))<<1, k = (i<<1)+1; j <= 500000000; j+=k)
			    prime[j>>5]|=(1<<(j&31));
}
inline bool isprime(register int x)
{
	return x == 2 || (x&1)&&!f(((x-1)>>1));
}
int main()
{
	make_p();
	int m, n;
	while(~scanf(" %d %d",&m,&n))
	{
		int c = 0;
		for(int i = m; i <= n; i++) if(isprime(i)) c++;
		printf("%d\n",c);
	}
	return 0;
}
