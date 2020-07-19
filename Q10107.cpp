/*
Problem: Q10107.cpp
Author: andyisman
Complete time: Sun Jan 17 14:45:32 2010
*/

#include <iostream>
#include <algorithm>
#define Max 10010
using namespace std;

int main()
{
	int in[Max],i=1,j,k;
	while(~scanf(" %d", &in[i++]))
	{
		j=i-2,k=i-1;
		while(in[j]>in[k]&&j)swap(in[j--],in[k--]);
		if((i-1)%2)printf("%d\n",in[i/2]);
		else printf("%d\n",(in[i/2]+in[i/2+1])/2);
	}
	return 0;
}
