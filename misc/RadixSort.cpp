#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100
int GetDigit(int num, int i)
{
	int j;
	for(j = 1; j < i; j++)
		num /= 10;
	return num % 10;
}
void RadixSort(int *num, int n)
{
	int digit[10][MAX + 1], i, j, sum, k, d;
	for(k = 1; k <= n; k++)
	{
		sum = 0;
		for(i = 0; i < 10; i++)
		    digit[i][0] = 1;

		for(i = 0; i < MAX; i++)
		{
			d = GetDigit(num[i], k);
		    digit[d][digit[d][0]++] = num[i];
		}
		for(i = 0; i < 10; i++)
			for(j = 1; j < digit[i][0]; j++)
			    num[sum++] = digit[i][j];
	}
}
int main()
{
	int num[MAX], i;
	for(i = 0; i < MAX; i++)
	{
		num[i] = 9000 - i * i + 5000;
		//printf("%d\n", GetDigit(num[i], 2));
	}
	RadixSort(num, 4);
	for(i = 0; i < 100; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
    system("pause");
    return 0;
}
