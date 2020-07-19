/*
ID: andypcu2
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>
int Mystrcmp(char *s1, char *s2)
{
	int lena = strlen(s1), i;
	int lenb = strlen(s2);
	if(lena != lenb)
	    return 0;
	else
  		for(i = 0; s1[i]; i++)
			if(s1[i] != s2[i]) return 0;
	return 1;
}
main ()
{
	char Name[11][15], in[15];
	int count[11], NP, i, m, p, tmp, per;
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    while(~fscanf(fin, " %d", &NP))
    {
		memset(count, 0, sizeof(count));
		i = NP;
		while(i--)
			fscanf(fin, "%s", Name[NP - i - 1]);
		while((~fscanf(fin, "%s", in)))
		{
            fscanf(fin," %d %d", &m, &p);
			for(i = 0; i < NP; i++)
			    if(Mystrcmp(Name[i], in))
			        per = i;
			if(p)
			{
				tmp = m / p;
				count[per] -= (m / p) * p;
			}
			while(p--)
			{
   				fscanf(fin, "%s", in);
				for(i = 0; i < NP; i++)
					if(Mystrcmp(Name[i], in))
					    count[i] += tmp;
			}
		}
		i = NP;
		while(i--)
			fprintf(fout, "%s %d\n", Name[NP - i - 1], count[NP - i - 1]);
	}
	fclose(fin); fclose(fout);
}
