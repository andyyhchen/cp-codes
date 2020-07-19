#include <iostream>
#define Max 3010
using namespace std;

int main()
{
	int n,num[Max],i=0;
	bool b[Max];
	while(~scanf(" %d",&n))
	{
  		for(int i=0;i<n;i++)
  		{
			b[i]=false;
			scanf(" %d",num+i);
		}
		int k,f=1;
  		for(int j=0;j<n-1;j++)
  		{
			k=abs(num[j]-num[j+1]);
			if(k<n&&k>0)
				if(b[k]){f=0;break;}
				else b[k]=true;
			else
				{f=0;break;}
		}
		if(f)printf("Jolly\n");
		else printf("Not jolly\n");
	}
}
