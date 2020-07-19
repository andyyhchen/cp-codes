#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH(x) ((((x) >> 2) + 55) % 31)
int HASHTABLE[31];
int Insert(int key)
{
	int i, j;
	i = j = HASH(key);
	if(HASHTABLE[i] == -1) {HASHTABLE[i] = key; return 1;}
	i++;
	while(i % 31 != j)
	{
		if(HASHTABLE[i % 31] == -1)
		{
			HASHTABLE[i%31] = key;
			return 1;
		}
		i++;
	}
	return 0;
}
int Delete(int key)
{
	int i, j;
	i = j = HASH(key);
	if(HASHTABLE[i] != -1) {HASHTABLE[i] = -1; return 1;}
	i++;
	while(i % 31 != j)
	{
		if(HASHTABLE[i%31] == key)
		{
			HASHTABLE[i%31] = -1;
			return 1;
		}
		i++;
	}
	return 0;
}
int main()
{
	memset(HASHTABLE, -1, sizeof(HASHTABLE));
	for(int i = 0; i < 12; i++)
	{
		Insert(i);
	}
	for(int i = 0; i < 31; i++)
	    printf("%d ", HASHTABLE[i]);

	system("pause");
	return 0;
}
