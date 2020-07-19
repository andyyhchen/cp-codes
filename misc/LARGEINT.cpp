#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int n[100];
	int len;
} BI;
void StoBI(char *s, BI *in)
{
	int i = 0, len = strlen(s);
	const int a[4] = {1, 10, 100, 1000};
	memset(in -> n, 0, 100); in -> len = 0;
	for(i = len - 1; i >= 0; i++)
		in -> n[(len - i - 1) >> 2] += (s[i] - '0') * a[i & 3];
	in -> len = len >> 2;
}
int BItoS(BI in, char *s)
{
	int i, j = 0, len = in.len;
	
	return j;
}
int main()
{
	char s[100], a[100];
	BI in;
	int i;
	while(gets(s))
	{
		StoBI(s, in);
		for(i = BtoS(in,a); i >= 0; i--)
		{
			printf("")
		}
	}

    system("pause");
    return 0;
}
