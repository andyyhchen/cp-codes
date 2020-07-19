#include <iostream>
#define Max 40010

using namespace std;

int main()
{
	int color[Max],n,m;
	while(~scanf(" %d %d",&n,&m)&&(m||n))
	{
		for(int i=0;i<=n+1;i++)color[i]=0;
		int v1,v2,f=0;
		while(m--)
		{
			scanf(" %d %d",&v1,&v2);
   			if(!color[v1]&&!color[v2])color[v1]=1,color[v2]=2;
			else if(!color[v1])color[v1]=color[v2]+1;
			else if(!color[v2])color[v2]=color[v1]+1;
			else if((color[v1]%2)==(color[v2]%2))f=1;
		}
		if(!f)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
