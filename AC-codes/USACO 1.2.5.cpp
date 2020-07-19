/*
ID : andypcu2
PROG : dualpal
LANG : C++
*/
#include <iostream>

using namespace std;

bool chk(int n, int base)
{
	int i = 0; char s[32];
	while(n)
	{
		s[i++] = n % base;
		n /= base;
	}
	for(int j = 0; j < --i; j++)
		if(s[i]!=s[j]) return false;
	return true;
}

int main()
{
	FILE *fin = fopen("dualpal.in","r");
	FILE *fout = fopen("dualpal.out","w");
	int n, s;
	while(~fscanf(fin," %d %d", &n, &s))
	{
		int c = 0;
		for(int i = s + 1; c<n; i++)
		{
			int t_c = 0;
			for(int j = 2; j < 11; j++)
			    if(chk(i,j))t_c++;
			if(t_c > 1)
			{
				c++;
				fprintf(fout,"%d\n",i);
			}
		}
	}
	return 0;
}
