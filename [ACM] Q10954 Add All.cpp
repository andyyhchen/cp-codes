#include<stdio.h>
#define L(x) (x) * 2
#define R(x) (x) * 2 + 1
#define PARENT(x) (x) / 2
#define HEAP_SIZE 1000
void swap(int *a, int *b)
{
	int tmp = *a;
	*a= *b;
	*b = tmp;
}
void Heap_Adjustment(int N, int heapsize, int *heap)
{
	int smallest = N;
	if(L(N) <= heapsize && heap[L(N)] < heap[N])
	    smallest = L(N);
	if(R(N) <= heapsize && heap[R(N)] < heap[smallest])
	    smallest = R(N);
	if(smallest != N)
	{
		swap(&heap[smallest], &heap[N]);
		Heap_Adjustment(smallest, heapsize, heap);
	}
}
void Build(int N, int heapsize, int *heap)
{
	int i;
	for(i = PARENT(heapsize); i >= 1; i--)
	{
        Heap_Adjustment(i, heapsize, heap);
	}
}
int main()
{
	int N, i, heap[HEAP_SIZE];
	while(~scanf(" %d", &N))
	{
		for(i = 1; i <= N; i++)
		{
			scanf(" %d", &heap[i]);
		}
		Build(N, N, heap);
		N = PARENT(N);
		for(i = 1; i <= N; i++)
		{
		}
	}
	
    return 0;
}
