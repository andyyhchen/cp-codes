#include<stdio.h>
#include<stdlib.h>
int Min(int a, int b){return (a < b) ? a : b;}
int FindMin(int *A, int s, int e)
{
	int m = (s + e) / 2;
	if(s == e)
	    return A[s];
	return Min(FindMin(A, s, m), FindMin(A, m+1, e));
}
int main()
{
	int i, a[100], ans;
	
	for(i = 0; i < 100; i++)
	{
		srand(100 - i);
		a[i] = rand() % 101 + 1;
	}
	for(i = 0; i < 100; i++)
	    printf("%d ", a[i]);
	printf("\n");
	ans = FindMin(a, 0, 99);
	printf("%d\n", ans);
	system("pause");
    return 0;
}
