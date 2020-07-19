#include <iostream>
#define max(a,b) (a)>(b) ? (a) : (b)
#define Max 1001

using namespace std;

int dp[Max][Max],in[Max],s,n;

int f(int i, int j)
{
	if(i>n-1||j<0) return 0;
	if(i==j)return in[i];
	if(!dp[i][j]) dp[i][j]=max((s-f(i,j-1)),s-f(i+1,j));
	return dp[i][j];
}

int main()
{
	while(~scanf(" %d",&n))
	{
		for(int i=0,sum=0;i<n;i++) scanf(" %d",in+i),s+=in[i];
		int ans=f(0,n-1);
		cout<<ans;
	}

	system("pause");
	return 0;
}
