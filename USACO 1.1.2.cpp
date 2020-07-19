/*
ID: andypcu2
LANG: C
TASK: ride
*/
#include <stdio.h>
main ()
{
	char C[7], G[7];
	int Ct, Gt, i, j;
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    while((~fscanf(fin, "%s", C)) && (~fscanf(fin, "%s", G)))
    {
		Ct = Gt = 1;
		for(i = 0; C[i]; i++)
		    Ct *= (C[i] - 'A' + 1);
		for(j = 0; G[j]; j++)
		    Gt *= (G[j] - 'A' + 1);
		Ct %= 47; Gt %= 47;
		if(Ct ^ Gt)
		    fprintf(fout, "STAY\n");
		else
		    fprintf(fout, "GO\n");
	}
	fclose(fin); fclose(fout);
}
