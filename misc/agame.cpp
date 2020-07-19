#include<stdio.h>
int per[2] = {0};
int dp[100][100] = {-1, -1};
int in[100];
int max(int a, int b)
{
	if(a >= b)
	    return a;
	else
	    return b;
}
int get(int s, int e, int now, int person)
{
	if(s > e)
	    return;
	if( ~ dp[s][e] )
	  	 per[person] += dp[s][e];
	else
		 max(get(s + 1, e, s, ! person), get(s, e - 1, e, ! person)) + in[now];
}

int main()
{
    return 0;
}
