#include <stdio.h>
#define Max 100010
char dp[Max];
/*char f(int i)
{
	if(i<0) return 1;
	if(!i) return dp[i]=0;
	if(dp[i]) return dp[i];
	return dp[i]=!f(i-1)||!f(i-3)||!f(i-10)||!f(i-51)||!f(i-93);
}*/
int main()
{
	int n,a;
	//for(int i=0;i<Max;i++) dp[i] = 0;
	const int d[5]={1,3,10,51,93};
	for(int i=0; i<Max; i++)
	    for(int j=0; j<5; j++)
	        if(i-d[j]>=0)dp[i]=dp[i]||!dp[i-d[j]];
	while(~scanf(" %d",&n))
	{
		while(n--)
		{
            scanf(" %d",&a); //f(a);
			if(dp[a]) printf("Andy\n");
			else printf("Billy\n");
		}
	}
	return 0;
}
