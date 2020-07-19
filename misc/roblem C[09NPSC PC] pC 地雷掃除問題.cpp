#include<stdio.h>
int main()
{
	int h, w, d, i, j, k, area, sum = 0, min = 0, flag, tmp, p;
	int map[501][501] = {0, 0};
	while( ~ scanf(" %d %d %d", &h, &w, &d))
	{
		sum = 0;
		min = h * w;
		for(i = 0; i < h; i++)
		{
			for(j = 0; j < w; j++)
			{
				scanf(" %d", &map[i][j]);
			}
		}
		flag = 1;
		for(i = w - 1; i >= 0; i--)
		{
			for(j = 0; j <= i; j++)
			{
				sum = 0;
				area = 0;
				for(k = 0; k < h; k++)
				{
					tmp = 0;
					for(p = i; p <= j; p++)
					{
						if(map[k][p] < 0)
						{
						    flag = 0;
						    sum = 0;
						    area = 0;
						}
						else
						    tmp += map[k][p];
					}
					if(flag)
					{
						sum += tmp;
						area += i - j + 1;
						if(sum >= d && area < min)
						    min = area;
					}
					else
					{
						flag = 1;
					}
				}
			}
		}
		if(min == h * w)
		    min = -1;
		printf("%d\n", min);
	}
    return 0;
}
