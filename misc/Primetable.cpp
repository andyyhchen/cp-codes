#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char prime[6250];
void creat(void)
{
	memset(prime, 0, sizeof(prime));
	int i, j;
	for(i = 3; i < 31623; i += 2)
	{
		for(j = i * i; j < 100000; j += i);
		{
			if((j ^ i))
			{
				if(j % i)
					prime[j >> 4] |= (1 << ((j >> 1) % 8));
			}
		}
	}
}
int main()
{
	int i,j;
	FILE *fout = fopen("a.txt", "w");
	creat();
	for(i = 0; i < 3000; i++)
	{
		for(j = 0; j < 8; j++)
		{
			    fprintf(fout,"%d ", (1 << j) & (prime[i]));
		}
	}
	system("pause");


    return 0;
}
