#include <iostream>

using namespace std;
int prime[2050];

void makePrime(void)
{
	for(int i=0;i<2050;i++)prime[i]=0;
	prime[0]=prime[1]=1;
	for(int i=2;i<47;i++)
		for(int j=i*i;j<2050;j++)
			if(j%i==0)prime[j]=1;
}
int main()
{
	int T,times[124];
	char in[2010];
	makePrime();
	while(~scanf(" %d",&T))
	{
		for(int t=1;t<=T;t++)
		{
			memset(times,0,sizeof(times));
			scanf(" %s",in);
			int len=strlen(in);
			sort(in,in+len);
			for(int i=0;i<len;i++) times[in[i]]++;
			int f=1;
			printf("Case %d: ",t);
		    for(int i=0;i<124;i++)
		        if(!prime[times[i]])printf("%c",i),f=0;
		    if(f)printf("empty");
		    printf("\n");
		}
	}
	return 0;
}
