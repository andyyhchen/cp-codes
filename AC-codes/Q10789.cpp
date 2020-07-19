#include <iostream>

using namespace std;

const char Ctable[63]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};

int Bs(char key)
{
	for(int i=0;Ctable[i];i++)if(Ctable[i]==key)return i;
}

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
	int T;
	char in[2010];
	int times[63];
	makePrime();
	while(~scanf(" %d",&T))
	{
		for(int t=1;t<=T;t++)
		{
			int flag=0;
			scanf(" %s",in);
			for(int i=0;i<63;i++)times[i]=0;
			for(int i=0;in[i];i++) times[Bs(in[i])]++;
			printf("Case %d: ",t);
			for(int i=0;i<63;i++)
			    if(!prime[times[i]])printf("%c",Ctable[i]),flag=1;
			if(!flag) printf("empty");
			printf("\n");
		}
	}
	return 0;
}
