/*
ID : andypcu2
PROG : palsquare
LANG : C++
*/
#include <iostream>

using namespace std;

const char digit[22] = {"0123456789ABCDEFGHIJ"};
FILE *fin = fopen("palsquare.in", "r");
FILE *fout = fopen("palsquare.out", "w");
bool chk(int n, int base)
{
	char s[20]; int i = 0, tmp = n; n *= n;
	while(n)
	{
		s[i++] = digit[n % base];
		n /= base;
	}
	int t_i = i;
	for(int j = 0; j < --i; j++)
		if(s[j] != s[i]) return false;
	char s1[20]; int j = 0;
	while(tmp)
	{
		s1[j++] = digit[tmp % base];
		tmp /= base;
	}
	int t_j = j;
	for(int k = t_j - 1; k >= 0; k--) fprintf(fout,"%c",s1[k]);
	fprintf(fout," ");
	for(int k = t_i - 1; k >= 0; k--) fprintf(fout,"%c",s[k]);
	fprintf(fout,"\n");
	return true;
}

int main()
{
	int n;
	while(~fscanf(fin," %d", &n))
	{
		for(int i = 1; i < 301; i++)
			chk(i, n);
	}
	return 0;
}
