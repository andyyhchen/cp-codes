#include<stdio.h>
int main()
{
	int in;
	while( ~ scanf(" %d", &in))
	    printf("%d\n", ( in - 1 ) * ( in + 2 ) / 2 + 2);
    return 0;
}
