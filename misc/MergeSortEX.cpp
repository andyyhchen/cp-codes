#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000000
int L[MAX], R[MAX];
//==============================================================================
//======================= Main Process of MergeSort ============================
//==============================================================================
void Move(int s, int e, int *from, int *to)
{
	int i;
	for(i = s; i <= e; i++)
	{
		to[i] = from[i];
	}
}

void Merge(int s, int m, int e, int *L, int *R)
{
	int i = s, j = m + 1, k = s;
	
	Move(m + 1, e, L, R);
	Move(s, m, L, R);
	while(i <= m && j <= e)
	{
		if(R[i] < R[j])
		{
			L[k++] = R[i++];
		}
		else
		{
			L[k++] = R[j++];
		}
	}
	if(i > m)
	{
		for(int p = j; p <= e; p++)
		    L[k++] = R[p];
	}
	else
	{
		for(int p = i; p <= m; p++)
		    L[k++] = R[p];
	}

}

void MergeSort(int s, int e, int *L, int *R)
{
	int mid = (s + e) / 2;
	if(s == e)
	    return;
	MergeSort(s, mid, L, R);
	MergeSort(mid + 1, e, L, R);
	
	Merge(s, mid, e, L, R);
	return;
}
//==============================================================================
//=============================Process Of Test==================================
//==============================================================================

void generate(int n, int seed, int *L) {
	int i;
	srand(seed);
	for (i=0; i<n; i++) {
		L[i] = rand() * rand();
	}
}

int main()
{
    double t_s, t_e, t_run;
    
    generate(MAX, 143141, L);
    
    printf("start sort:  %d  numbers\n", MAX);
    printf("=====================================\n");

	t_s = clock();
    
	MergeSort(0, MAX - 1, L, R);
	
	t_e = clock();
	t_run = (t_e - t_run) / CLOCKS_PER_SEC;
	
	/*
	for(int k = 0; k < MAX; k++)
	    printf("%d ", L[k]);
	*/
	printf("running time: %5.5f\n", t_run);
	
	system("pause");
	
    return 0;
}
