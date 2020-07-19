#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define R(x) (((x) << 1) | 1)
#define L(x) (x) << 1
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void HeapAdjust(int *heap, int root, int HEAPSIZE)
{
	int small = root;
	if(R(root) <= HEAPSIZE && heap[root] > heap[R(root)]) small = R(root);
	if(L(root) <= HEAPSIZE && heap[small] > heap[L(root)]) small = L(root);
	Swap(&heap[root], &heap[small]);
	if(small != root) HeapAdjust(heap, small, HEAPSIZE);
}
void BuildHeap(int *heap, int HEAPSIZE)
{
	int n = HEAPSIZE >> 1, i;
	for(i = n; i > 0; i--) HeapAdjust(heap, i, HEAPSIZE);
}
void Delete(int *heap, int HEAPSIZE)
{
	Swap(&heap[1], &heap[(HEAPSIZE)--]);
	HeapAdjust(heap, 1, HEAPSIZE);
}
void Insert(int *heap, int key, int HEAPSIZE)
{
	int i = HEAPSIZE + 1;
	heap[i] = key;
	while(i > 1)
	{
		i = i >> 1;
		HeapAdjust(heap, i, HEAPSIZE + 1);
	}
}
int main()
{
	int i, heap[1000];
	//for(i = 1; i < 1000; i++) Insert(heap, 10 - i, i - 1);
	for(i = 1; i < 1000; i++) heap[i] = 1021 - i;
	
	BuildHeap(heap, 999); Delete(heap, 999);
	for(i = 1; i < 1000; i++)
	   printf("%d ", heap[i]);
	system("pause");
	return 0;
}
