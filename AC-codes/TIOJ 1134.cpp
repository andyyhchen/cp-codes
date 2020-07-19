#include <iostream>
using namespace std;
int map[201][201],sum[201];
int main()
{
	int t,n,m,ms,s,p,k,i,j;
	cin>>t;
	while(t--&&cin>>n>>m){
		ms = 0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				scanf("%d",&map[i][j]);
				if(!map[i][j])map[i][j]=-1;
			}
		for(i=0;i<n;i++){
			memset(sum,0,sizeof(sum));
			for(j=i;j<n;j++){
				for(k=0;k<m;k++)sum[k]+=map[j][k];
				for(p=0;p<m;p++)
					for(k=p,s=sum[k];k<m;k++,s+=sum[k])
						if(s<0)ms=max(ms,(j-i+1)*(k-p+1));
			}
		}
		printf("%d\n",ms);
	}
	return 0;
}
