#include <iostream>
#define Max 5001
using namespace std;

int f[Max][Max];

int main()
{
	f[0][0]=0;f[1][0]=1;
	for(int i=2;i<Max;i++)
	{
		for(int j=0;j<Max-1;j++)
		{
			f[i][j]+=f[i-1][j]+f[i-2][j];
			f[i][j+1]+=f[i][j]/10;
			f[i][j]%=10;
		}
	}
	int n;
	while(~scanf(" %d",&n))
	{
		int t=Max-1;
		cout<<"The Fibonacci number for "<<n<<" is ";
		if(n==0)printf("0\n");
		else
		{
   			while(!f[n][t--]);
			for(int i=t+1;i>=0;i--)
			    printf("%d",f[n][i]);
			printf("\n");
		}
	}
	return 0;
}
