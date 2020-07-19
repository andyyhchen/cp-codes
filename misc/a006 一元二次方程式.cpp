#include<stdio.h>
#include<math.h>
int a, b, c;
int ans;
int p(void)
{
	if(b * b - 4 * a * c > 0)
	    return 1;
	if(b * b - 4 * a * c == 0)
	    return 2;
	if(b * b - 4 * a * c < 0)
	    return 0;
}
int main()
{

	while(~scanf(" %d %d %d" ,&a, &b, &c))
	{
        ans = (int)(sqrt((double)( b * b - 4 * a * c ))+0.001);
		switch(p())
		{
			case 1:
				printf("Two different roots x1=%d , x2=%d\n", (-b + ans) /(2*a), (-b - ans) /(2*a));
				break;
			case 2:
				printf("Two same roots x=%d\n", -b / (2*a));
				break;
			case 0:
					printf("No real root\n");
		}
	}
    return 0;
}
