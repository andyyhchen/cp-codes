#include<stdio.h>
#include<stdlib.h>
int RtoI(char c)
{
	switch(c)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}
}
int PROCESS(char *s)
{
	int i, ans = 0;
	for(i = 0; s[i]; i++)
	{
		if(RtoI(s[i]) >= RtoI(s[i + 1]))
			ans += RtoI(s[i]);
		else
		    ans -= RtoI(s[i]);
	}
	return ans;
}
void ItoR(char *in, int n)
{
	int i = 0, j = 0, k;
	int m[13] =  {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char s[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	while(i < 13)
	{
		if(n >= m[i] && n - m[i] >= 0)
		{
			for(k = 0; s[i][k]; k++)
			    in[j++] = s[i][k];
			n -= m[i];
		}
		else
		{
			i++;
		}
	}
	in[j] = '\0';
}
int main()
{
	char ans[5000], ina[5000], inb[5000];
	int tmp;
	//FILE *fin = fopen("roman.in", "r");
	//FILE *fout = fopen("roman.out", "w");
	while(~scanf("%s %s", ina, inb))
	{
		if(ina[0] == '#')
		    break;
		tmp = abs(PROCESS(ina) - PROCESS(inb));
		ItoR(ans, tmp);
		if(!tmp)
		    printf("ZERO\n");
		else
			printf("%s\n", ans);
	}
	//fclose(fin);
	//fclose(fout);
    return 0;
}
