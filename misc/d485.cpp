#include<stdio.h>
int main()
{
	int a, b;
	while(~scanf(" %d %d", &a, &b))
	{
		if(a == b)
		{
			if(!(a % 2))
			    printf("1\n");
			else
			    printf("0\n");
		}
		else
	    	printf("%d\n" ,(b - a) / 2 + 1);
	}
    return 0;
}
