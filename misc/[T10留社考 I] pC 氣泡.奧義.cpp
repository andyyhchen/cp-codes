#include<stdio.h>
int main()
{
	int i, t, k, ans[6] = {0}, re = 0, j, ;           //'R'¡B'G'¡B'B'¡B'Y'¡B'P'¡B'X'
	char a[12][6];                          // 0    1    2    3    4    5
	//while(~scanf(" %d", &t))
	//{
		scanf(" %d", &t);
		printf("\n");
		for(i = 0; i < t; i++)
		{
			re = 0;
			for(k = 0; k < 5; k++)
			    ans[k] = 0;
			for(k = 0; k < 12; k++)
			{
				for(j = 0; j < 6; j++)
					scanf(" %c", &a[k][j]);
			}
			
			for(k = 0; k < 12; k++)
			{
				for(j = 0; j < 6; j++)
				{
					switch(a[k][j])
					{
						case 'R':
								ans[0] = 1;
								break;
						case 'G':
								ans[1] = 1;
								break;
                        case 'B':
								ans[2] = 1;
								break;
						case 'Y':
								ans[3] = 1;
								break;
						case 'P':
								ans[4] = 1;
								break;
						case 'X':
								ans[5] = 1;
								break;
					}
				}
			}
			for(k = 0; k < 5; k++)
			    if(ans[k])
			        re++;
			printf("%d\n", re);
		}
		
	//}
    return 0;
}
