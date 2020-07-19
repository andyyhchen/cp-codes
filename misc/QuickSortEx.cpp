#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100000000
int A[MAX_SIZE];
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int QuickSort(int s, int e, int *A)
{
	int i, j = s, key;
	if(s < e)
	{
		swap(&A[e], &A[rand() % (s - e) + s]);
		for(i = s; i < e; i++)
			if(A[i] < A[e])
				swap(&A[i], &A[j++]);
		swap(&A[j], &A[e]);
		QuickSort(s, j - 1, A);
		QuickSort(j + 1, e, A);
	}

}
void generate(int n, int seed, int *A) {
	int i;
	srand(seed);
	for (i=0; i<n; i++) {
		A[i] = rand()*rand();
	}
}
int main()
{
	double t_s, t_e, t_run;

	generate(MAX_SIZE, 143141, A);
	printf("Start Sort %d Numbers\n", MAX_SIZE);
	printf("=================================\n");
	t_s = clock();

	QuickSort(0, MAX_SIZE - 1, A);

	t_e =  clock();
	t_run = (t_e - t_s) / CLOCKS_PER_SEC;
	printf("Running Time: %5.5f\n", t_run);

	system("pause");
    return 0;
}
