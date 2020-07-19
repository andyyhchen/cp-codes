#include <stdio.h>
int m(int i)
{
	if(!i) return 1;
	return i * m(i - 1);
}
int main(int n)
{
	while(~scanf(" %d", &n)) printf("%d\n", m(n));
	return 0;
}
