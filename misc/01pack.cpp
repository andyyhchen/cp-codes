#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000
#define MAX(a , b) ((a) > (b)) ? a : b
int W[MAXSIZE], V[MAXSIZE], DP[MAXSIZE][MAXSIZE], N;
int F(int i, int c)
{
	if(i < N - 1)
	{
		if(W[i] <= c)
			if(DP[i][c] == -1){DP[i][c] = MAX(F(i + 1, c - W[i]) + V[i], F(i + 1, c)); return DP[i][c];}
		    else return DP[i][c];
	}
	else
	{
	    if(W[i] <= c) {DP[i][c] = V[i]; return DP[i][c];}
	    else {DP[i][c] = 0; return 0;}
	}
}
int main()
{
	memset(DP, -1, sizeof(DP));
	int i = 0; N = 3;
	for(i = 0; i < N; i++) scanf(" %d %d", &W[i], &V[i]);
	printf("%d\n", F(0, 6));
	system("pause");
}
