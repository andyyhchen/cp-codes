/*
ID: andypcu2
LANG: C
TASK: beads
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");
	int N, i, j ,tmp1[700], tmp2[700], max, r[700], b[700];
	char Necklace[350];
	while(~fscanf(fin," %d", &N))
	{
		max = 0;
		memset(b, 0, sizeof(b)); memset(r, 0, sizeof(r));
		fscanf(fin, "%s", Necklace);
	    for(i = 0; i < N; i++)
		{
			if(Necklace[i] == 'r' || Necklace[i] == 'w') r[i] = 1;
			if(Necklace[i] == 'b' || Necklace[i] == 'w') b[i] = 1;
		}
		for(i = 0; i < 2 * N; i++)
			tmp1[i] = tmp2[i] = r[i % N];
		for(j = 1; j < 2 * N; j++)
		    if(tmp1[j]) tmp1[j] += tmp1[j - 1];
		for(j = 2 * N - 2; j >= 0; j--)
		    if(tmp2[j]) tmp2[j] += tmp2[j + 1];
		for(j = 0; j < 2 * N; j++)
		{
		    r[j] = tmp1[j] + tmp2[j];
		}
		for(i = 0; i < 2 * N; i++)
			tmp1[i] = tmp2[i] = b[i % N];
		for(j = 1; j < 2 * N; j++)
		    if(tmp1[j]) tmp1[j] += tmp1[j - 1];
		for(j = 2 * N - 2; j >= 0; j--)
		    if(tmp2[j]) tmp2[j] += tmp2[j + 1];
		for(j = 0; j < 2 * N; j++)
		{
		    b[j] = tmp1[j] + tmp2[j];
		}
		for(i = 0; i < 2 * N; i++)
		{
		    tmp1[i] = b[i] + r[i];
		}
		for(i = 0; i < 2 * N; i++)
   			if(tmp1[i] > max) max = tmp1[i];
   		if(max > N)
   		    max = N;
		fprintf(fout, "%d\n", max );
	}
	fclose(fin); fclose(fout);
    return 0;
}
