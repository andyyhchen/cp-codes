/*
Problem: Q10589.cpp
Author: andyisman
Complete time: Sun Jan 17 19:30:06 2010
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N,c,a,t;
	double x,y;
	while(~scanf(" %d %d",&N,&a)&&a&&N)
	{
		c=0;t=N;
		while(t--&&scanf(" %lf %lf",&x,&y))
   			if(((pow(x,2)+pow(y,2))<=pow(a, 2))&&((pow(x-a,2)+pow(y-a,2))<=pow(a,2))&&((pow(x-a,2)+pow(y,2))<=pow(a,2))&&((pow(x,2)+pow(y-a,2))<=pow(a,2)))c++;
		double ans=(double)c/(double)N*(double)a*(double)a;
		printf("%.5f\n",ans);
	}
	return 0;
}
