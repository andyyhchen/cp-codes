#include <stdio.h>
unsigned int prime[15630];
inline void make_p()
{
	register unsigned int i, j, k;
	#define f(x) ((prime[((x)>>5)]>>((x)&31))&1)
	for(i = 1; i < 502; i++)
		if(f(i)==0)
			for(j = (i*(i+1))<<1, k = (i<<1)+1; j <= 500000; j+=k)
			    prime[j>>5]|=(1<<(j&31));
}
inline bool isprime(register int x)
{
	return x == 2 || (x&1)&&!f(((x-1)>>1));
}
inline int getint()
{
	register char c;
	register int ans = 0;
	while((c = getchar())!='\n') ans = ans*10+(c-'0');
	return ans;
}
int main()
{
	make_p();
	register int n, i, f;
	while((n = getint())&&n)
	{
		f = 0;
		for(i = 2; i <= ((n+1)>>1); i++)
			if((f=isprime(i)&&isprime(n-i))) break;
		if(f)
			printf("%d = %d + %d\n",n,i,n-i);
		else
		    printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
