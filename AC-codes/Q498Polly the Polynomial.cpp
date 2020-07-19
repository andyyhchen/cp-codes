#include<stdio.h>
int pow(int base, int n)
{
	int i, a = 1;
	if(n == 0) return base;
	for(i = 0; i < n; i++)
		a *= base;
	return a;
}

int main()
{
	
}
