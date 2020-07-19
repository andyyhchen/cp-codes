#include <stdio.h>
#include <math.h>
#define Max 1000001
int a[Max],f[Max];

int num()
{
	int th,tmp;
	a[1] = f[1] = 0, a[2] = f[2] = 1;
	for(int i=3;i<Max;i++)
	{
		th = (int)sqrt(i), tmp = 1;
		for(int j=2;j<=th;j++)
		{
			if(i%j==0)
			{
				tmp=j;
				break;
			}
		}
		if(tmp==1)a[i]=1;
		else a[i]=a[tmp]+a[i/tmp];
		f[i] = f[i-1] + a[i];
	}
}



int main()
{
	int n;
	num();
	while(~scanf(" %d",&n))
	    printf("%d\n",f[n]);
	return 0;
}
