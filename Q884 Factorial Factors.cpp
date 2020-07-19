#include<stdio.h>
char table[1005] = {1};
void build(void)
{
	table[0] = table[1] = 0;
	int i, j;
	for(i = 2; i < 35; i++)
	{
		for(j = 2; j < 1001; j++)
		{
			if(!(j % i) && (j - i))
			    table[j] = 0;
		}
	}
}
int main()
{
	int in = 0;
	while(~scanf(" %d", &in))
	{
		for(k = in; k > 1; k++)
		{
			for(p = )
		}
	}
}
