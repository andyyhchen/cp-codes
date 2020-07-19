#include<stdio.h>
#define MAX 20000000
int num[MAX];
int L[MAX + 10] = {0}, R[MAX + 10] = {0};
void mg(int a, int b, int c)
{
	int i, j, k;
	for(i = a; i <= b; i++)
     	L[i - a] = num[i];
	for(j = b + 1; j <= c; j++)
		R[j - b - 1] = num[j];
	R[j - b - 1] = 2147483647;
	L[i - a] = 2147483647;
	i = j = 0;
	for(k = a; k <= c; k++)
	{
		if(R[j] >= L[i])
		{
			num[k] = L[i];
			i++;
		}
		else
		{
			num[k] = R[j];
			j++;
		}
	}
	return;
}
void mgs( int q, int p)
{
	int r = ( q + p ) / 2;
	if(q < p)
	{
		mgs(q, r);
		mgs(r + 1, p);
		mg( q, r, p);
		return;
	}
}

int main()
{

 for(int y = 0; y < MAX; y++)
		num[y] = 10000 - y;                  //creat number
 	mgs(0, MAX - 1);
 
		 printf("done\n");              //print number
	while(1);
    return 0;
}

