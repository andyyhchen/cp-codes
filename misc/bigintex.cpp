#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(char *inae, char *inbe)
{
    int i, lena, lenb;
    lena = strlen(inae);
	lenb = strlen(inbe);
	if(lena > lenb)
	    return 1;
	if(lena < lenb)
	    return 2;
	if(lena == lenb)
	{
		for(i = 0; i < lenb; i++)
		{
			if(inae[i] > inbe[i])
				return 1;
			else if(inae[i] < inbe[i])
			    return 2;
		}
		return 3;
	}
}

int max(int a ,int b)
{
	if(b > a)
	    return b;
	else
	    return a;
}
void reset(int *ans, int len)
{
	int i;
	for(i = 0; i < len; i++)
	    ans[i] = 0;
}
int add(char *a, char *b, int *ans, int len)
{
	int i, lena, lenb;
	reset(ans, len);
	lena = strlen(a);
	lenb = strlen(b);
	for(i = 0; a[i]; i++)
		ans[lena - 1 - i] += a[i] - '0';
	for(i = 0; b[i]; i++)
	    ans[lenb - 1 - i] += b[i] - '0';
	lena = max(lena, lenb);
	for(i = 0; i < lena; i++)
	{
		ans[i + 1] += ans[i] / 10;
		ans[i] = ans[i] % 10;
	}
	return lena;
}
int sub(char *a, char *b, int *ans, int len)
{
	int i, lena, lenb;
	reset(ans, len);
	lena = strlen(a);
	lenb = strlen(b);
	for(i = 0; a[i]; i++)
		ans[lena - 1 - i] += a[i] - '0';
	for(i = 0; b[i]; i++)
	    ans[lenb - 1 - i] -= b[i] - '0';
	lena = max(lena, lenb);
	for(i = 0; i < lena; i++)
	{
		if(ans[i] < 0)
		{
		    ans[i + 1] -= 1;
		    ans[i] += 10;
		}
	}
	return lena;
}
int mult(char *a, char *b, int *ans, int len)
{
	int i, lena, lenb, j;
	reset(ans, len);
	lena = strlen(a);
	lenb = strlen(b);
	for(i = lena - 1; i >= 0; i--)
	{
		for(j = lenb - 1; j >= 0; j--)
		{
			ans[lenb - 1 - j + lena - 1 - i] += (a[i] - '0') * (b[j] - '0');
		}
	}
	for(i = 0 ;i < lena + lenb - 1; i++)
	{
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	return lena + lenb - 1;
}
int main()
{
	char a[100], b[100];
	int ans[200], len = 200, re, j;
	while(gets(a))
	{
		gets(b);
		re = mult(a, b, ans, len);
		printf("%d\n", compare(a, b));

		if(ans[re] != 0)
		    printf("%d", ans[re]);
		for(j = re - 1; j >= 0; j--)
			printf("%d", ans[j]);
		printf("\n");
	}
	system("PAUSE");

    return 0;
}
