#include<stdio.h>
#include<stdlib.h>
int in[3000];
int main()
{
	int i, prev, n;
	//int p;
	char flag = 1, flag2 = 1;
	while(~scanf(" %d", &n))
	{
		for(i = 0; i < n; i++)
			scanf(" %d", &in[i]);
		//n = 10000;
		//p =  10000000;

		//for(i = 0; i < 10000; i++)
		//{
		//	p -= i;
			//in[i] = p;
		//}

		prev = 1;
		flag = 1;
		flag2 = 1;

		for(i = 1; i < n; i++)
		{
			if(abs(in[i - 1] - in[i]) != prev)
			{
				flag = 0;
				break;
			}
			prev ++;
		}
		prev = n - 1;
		for(i = 1; i < n; i++)
		{
			if(abs(in[i - 1] - in[i]) != prev)
			{
				flag2 = 0;
				break;
			}
			prev --;
		}
		if( flag == 1 || flag2 == 1)
		    printf("Jolly\n");
		else
		    printf("Not Jolly\n");
	}
    return 0;
}
