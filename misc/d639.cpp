
#include <stdio.h>
#define mod 10007
struct M
{
	int r,c;
	int a[3][3];
};
M operator*(const M a, const M b)
{
	M c;
	int p=a.r,q=a.c,r=b.c;
	int i,j,k;
	for (i=0;i<p;i++)
		for (j=0;j<r;j++)
			c.a[i][j]=0;
	for (i=0;i<p;i++)
		for (j=0;j<r;j++)
			for (k=0;k<q;k++)
			{
				c.a[i][j]+=a.a[i][k]*b.a[k][j];
				c.a[i][j]%=mod;
			}
	c.r=p;
	c.c=r;
	return c;
};
int main()
{
	M org={3,3,{{0,1,0},{0,0,1},{1,1,1}}};
	M res={3,3,{{1},{1},{1}}};
	int n;
	scanf("%d",&n);
	n--;
	while (n)
	{
		if (n&1)
		{
		    res = org * res;
		}
		org = org * org;
		n>>=1;
	}
	printf("%d",res.a[0][0]);while(1);
	return 0;
}
