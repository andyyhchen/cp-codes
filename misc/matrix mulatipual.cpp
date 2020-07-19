#include <iostream>

const int I = 2, J = 2, K = 3;

using namespace std;

int A[I][J], B[J][K], C[I][K];

int main()
{
	memset(A, 0, sizeof(A));memset(B, 0, sizeof(B));memset(C, 0, sizeof(C));
	
	for(int i = 0; i < I; i++)
		for(int j = 0; j < J; j++) scanf(" %d", &A[i][j]);
		
	cout << endl;
	
	for(int i = 0; i < I; i++)
		for(int j = 0; j < J; j++) scanf(" %d", &B[i][j]);
		
	for(int i = 0; i < I; i++)
	{
		for(int k = 0; k < K; k++)
		{
			for(int j = 0; j < J; j++)
			{
				C[i][k] += A[i][j] * B[k][j];
			}
		}
	}
	
	cout << "\n";
	
	for(int i = 0; i < I; i++)
	{
		for(int k = 0; k < K; k++)
		{
			printf("%5d ", C[i][k]);
		}
		printf("\n");
	}

	system("pause");
	
	return 0;
}
