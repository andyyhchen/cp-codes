/*
ID: andypcu2
PROG: beads
LANG: C++
*/

#include <iostream>
#include <string.h>
#define Max 351
using namespace std;

int main()
{
	FILE *in = fopen("beads.in","r");
	FILE *out = fopen("beads.out","w");
	char bead[Max * 2], nowc;
	int n, a, b, m, w;
	fscanf(in, " %d", &n);
	fscanf(in, " %s", bead);
	memcpy(bead + n, bead, n);
	a = b = m = nowc = w = 0;
	for(int i = 0; bead[i] && n > m; i++)
	{
		if(bead[i] == 'w') w++, b++;
		else if(nowc != bead[i])
		{
			if(a + b > m) m = a + b;
			a = b - w; b = w + 1; w = 0; nowc = bead[i];
		}
		else
			b++, w = 0;
	}
	
	if(a + b > m) m = a + b;
	fprintf(out,"%d\n",(m > n) ? n : m);
	fclose(in); fclose(out);
	return 0;
}
