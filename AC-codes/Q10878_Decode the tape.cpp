#include<stdio.h>
int mystrlen(char *s)
{
	int i;
	for(i = 0; s[i]; i++);
	return i;
}
int mystrcmp(char *a, char *b)
{
	int lena, lenb, j;
	char flag = 1;
	lena = mystrlen(a);
	lenb = mystrlen(b);
	if(lena != lenb)
		return 0;
	for(j = 0; j < lena; j++)
	{
		if(a[j] != b[j])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}


char ans[1000] = {0};
int main()
{
	int i = 0, j = 0;
	char in[11];
	while(gets(in))
	{
		j = 0;
		for(i = 0; i< 1000; i++ )
		    ans[i] = 0;
		while( gets(in))
		{
			
			if(mystrcmp(in, "___________"))
			    break;
			if( ~ mystrcmp(in, "___________") )
			{
				for(i = 0; i < 11; i++)
				{
					if(in[i] == 'o')
						in[i] = 1;
					else
					    in[i] = 0;
				}
				ans[j] += 0x40*in[2]+0x20*in[3]+0x10*in[4]+0x8*in[5]+0x4*in[7]+0x2*in[8]+in[9];
				j++;
			}


		}
		for(i = 0; i < j; i++)
			printf("%c", ans[i]);
		
	   	}
		   return 0;
	}
	
	
