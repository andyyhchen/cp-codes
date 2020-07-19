#include <iostream>
#define Max 600
using namespace std;

typedef struct bignumber{
	int n[Max];
	int len;
}bignum;

void multiple(bignum a, bignum b, bignum &ans)
{
	if((a.n[0]==0&&a.len==0)||(b.n[0]==0&&b.len==0))
	{
		ans.n[0]=0;
		ans.len=0;
		return;
	}
	int lena=a.len,lenb=b.len;
	memset(ans.n,0,sizeof(ans.n));
	for(int i=0;i<=lena;i++)
	{
		for(int j=0;j<=lenb;j++)
		{
			ans.n[j+i]+=a.n[i]*b.n[j];
			ans.n[j+1+i]+=ans.n[j+i]/10;
			ans.n[j+i]%=10;
		}
	}
	int i=lena+lenb+10;
	while(!ans.n[i])i--;
	ans.len=i;
}


int main()
{
	char L1[Max],L2[Max];
	while(gets(L1)&&gets(L2))
	{
		int i;
		bignum a,b,ans;
		for(i=0;L1[i];i++) L1[i]-='0';
		int j;
		for(j=0;L2[j];j++) L2[j]-='0';
		j--;i--;
		for(int k=i;k>=0;k--) a.n[k]=L1[i-k];
		for(int k=j;k>=0;k--) b.n[k]=L2[j-k];
		a.len=i;b.len=j;
		multiple(a,b,ans);
		for(i=ans.len;i>=0;i--)printf("%d",ans.n[i]);
		printf("\n");
	}
	return 0;
}
