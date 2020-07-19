#include<stdio.h>
int arr[10];
int main()
{
	int key, k = 0;
	for(int i = 0; i < 10;i++)
	    arr[i] = 100 + i;
	for(int i = 1; i < 10; i++)
	{
		key = arr[i];
		k = i - 1;
		while(k >= 0 && key > arr[k])
		{
			arr[k + 1] = arr[k];
			k--;
		}
		arr[k + 1] = key;
	}
    for(int i = 0; i < 10;i++)
        printf("%d ", arr[i]);
        while(1);
    return 0;
}
