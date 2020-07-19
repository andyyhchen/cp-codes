#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
struct BigInt {
	int I[MAX];
	int len;
};
typedef struct BigInt LargeInt;
void Add(LargeInt *a, LargeInt *b, LargeInt *ans)
{
	int i;
	if(a->I[0] == 0 && b->I[0] == 0){ans->len = 0; ans->I[0] = 0; return;}
	//memset(&(ans->I), 0, sizeof(ans->I));
	for(i = 0; (a->I[i] || b->I[i]) && i < MAX; i++)
	{
		ans->I[i] += a->I[i] + b->I[i];
		ans->I[i + 1] += ans->I[i] / 10000;
		ans->I[i] %= 10000;
	}
	ans->len = i - 1;
}
void CtoI(char *s, LargeInt *in)
{
	memset(&(in -> I), 0, MAX);
	int Q[4] = {1, 10, 100, 1000}, i;
	int len = strlen(s);
	char tmp;
	for(i = (len - 1) / 2; i >= 0; i--)
	{
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
	}
	for(i = 0; i < len; i++)
	{
		in -> I[i / 4] += (s[i] - '0') * Q[i % 4];
	}
	in -> len = (i - 1) / 4;
}
int main()
{
	LargeInt a, b, c;
	char s1[MAX], s2[MAX];
	int i;
	memset(&(c.I), 0, sizeof(c.I));
	memset(&(b.I), 0, sizeof(b.I));
 	while(gets(s1))
	{
		if(s1[0] == '0') break;
		CtoI(s1, &a);
		Add(&a, &b, &c);
	}
	for(i = c.len; i >= 0; i--)
	    printf("%d", c.I[i]);
	printf("\n");
	//system("pause");
    return 0;
}
