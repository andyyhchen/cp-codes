#include <iostream>
#define Max 1000
using namespace std;

typedef struct vertex{double Lx,Ly,Rx,Ry;} V;

V ver[Max];

int main()
{
	char c;
	int i=0,count=0;
	while(scanf(" %c",&c)&&c!='*') scanf(" %lf %lf %lf %lf",&ver[i++].Lx,&ver[i].Ly,&ver[i].Rx,&ver[i].Ry);
	double x,y;
	while(scanf(" %lf %lf",&x,&y)&&x!=9999.9&&y!=9999.9)
	{
		count++;bool f=false;
		for(int j=0;j<i;j++)
			if(x>ver[j].Lx&&y<ver[j].Ly&&x<ver[j].Rx&&y>ver[j].Ry)
			    printf("Point %d is contained in figure %d\n",count,j+1),f=true;

		if(!f)printf("Point %d is not contained in any figure\n",count);
	}
	return 0;
}
