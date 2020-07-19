#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,i,j,m,x;
	vector <int> a[201];
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
			a[i].clear();
			a[i].push_back(-2000000000);
		}
		for(i=0,m=0;i<n;i++){
			scanf("%d",&x);
			for(j=0;j<m;j++)
				if(a[j][a[j].size()-1]<x)break;
			a[j].push_back(x);
			if(j>=m)m=j+1;
		}
		printf("%d\n",m);
	}
	return 0;
}
