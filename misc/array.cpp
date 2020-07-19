#include <iostream>
#define Max 10

using namespace std;

int array[Max];

void insert(int index, int in)
{
	for(int i = index; i < Max - 1; i++)
		array[i + 1] = array[i];
	array[index] = in;
}
void Delete(int index)
{
	for(int i = index + 1; i < Max; i++)
		array[i - 1] = array[i];
}
void reverse(void)
{
	int j = Max - 1, tmp;
	for(int i = 0; j - 2 * i > 0; i++)
	{
		tmp = array[i];
		array[i] = array[j - i];
		array[j - i] = tmp;
	}
}
int main()
{
	for(int i = 0; i < Max; i++)
	{
		array[i] = i;
	}
	reverse();
	Delete(3);
	insert(3, 10);
	for(int i = 0; i < Max; i++)
	    printf("%d ", array[i]);

	system("pause");
	return 0;
}
