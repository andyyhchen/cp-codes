#include <iostream>
#include <stdio.h>
using namespace std;

int A[3][3], B[3][1], L[31][3][3];

int main()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			scanf(" %d", &A[i][j]);
	}
	cout << "\n";
	for(int i = 0; i < 3; i++)
	{
		scanf(" %d", &B[i][0]);
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			L[0][i][j] = A[i][j];
		}
	}
	for(int i = 1; i < 31; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				int a = 0;
				for(int h = 0; h < 3; h++)
				{
					a += L[i - 1][j][h] * A[h][k];
				}
				L[i][j][k] = a;
			}
		}
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%d ", L[2][i][j]);
		}
		cout << "\n";
	}
	

	return 0;
}
