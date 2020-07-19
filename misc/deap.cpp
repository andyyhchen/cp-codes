/*deap*/

#include <iostream>
#define Max 100

using namespace std;

int MaxHeap[Max], MinHeap[Max];

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void MaxInsert(int p, int k)
{

	
}

void MinInsert(int p, int k)
{

}
int main()
{
	for(int i = 1; i < 10; i++)
		MinInsert(i, (i  * 3 )% 10 );
//	for(int i = 1; i < 12; i++)
	//printf("%d ", MinHeap[i]);
	system("pause");
	return 0;
}
