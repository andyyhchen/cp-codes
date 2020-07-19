#include<stdio.h>
int main()
{
	int a,b,c,d,i,t;
    while(~scanf(" %d", &t))
	{
		for(i = 0; i < t; i++)
		{
            scanf(" %d %d %d %d" ,&a, &b, &c, &d);
			if((b - a) == (c - b))
			    printf("%d %d %d %d %d\n", a, b, c, d, d + (b - a));
			else
				printf("%d %d %d %d %d\n", a, b, c, d, d * (b / a));
		}
	}
    return 0;
}
