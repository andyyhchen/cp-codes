#include<stdio.h>
#define PARENT(x) (x) / 2
#define LEFT(x) (x) * 2
#define RIGHT(x) (x) * 2 + 1
#define HEAP_SIZE 10
int heap[HEAP_SIZE];
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void heap_adjustment(int *heap, int n, int heapsize)
{
	int largest = n;
	if(LEFT(n) <= heapsize && heap[LEFT(n)] > heap[n])
	    largest = LEFT(n);
	if(RIGHT(n) <= heapsize && heap[RIGHT(n)] > heap[largest])
	    largest = RIGHT(n);
	if(largest != n)
	{
		swap(&heap[largest], &heap[n]);
		heap_adjustment(heap, largest, heapsize);
	}
}
void heap_build(int *heap, int in)
{
	int i = in / 2, j;
	for(j = i; j > 0; j--)
	{
        heap_adjustment(heap, j, HEAP_SIZE);
	}
}
void heap_sort(int *heap, int i)
{
	int k = i;
	for(k = i; k > 1; k--)
	{
		swap(&heap[1], &heap[k]);
		heap_adjustment(heap, 1, k - 1);
	}
}

int main()
{
	
	for(int y = 1; y < HEAP_SIZE; y++)  //generate num
	    heap[y] = 1000 + y;
	printf("generate done\n");
	heap_build(heap, HEAP_SIZE - 1);
//	heap_sort(heap, HEAP_SIZE - 1);
	for(int y = 1; y < HEAP_SIZE; y++) // print
	   printf("%d ", heap[y]);
	 printf("done\n");
	while(1);
    return 0;
}
