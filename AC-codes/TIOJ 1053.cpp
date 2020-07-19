#include<stdio.h>
int main()
{
	int a, b;
	while( ~ scanf(" %d %d", &a, &b))
	{
		if(b > a)
		{
            a ^= b;
            b ^= a;
        	a ^= b;
		}
		if( ! ( a % b ) )
		    printf("Y\n");
  		else
  		    printf("N\n");
	}
    return 0;
}
