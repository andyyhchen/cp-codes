#include <stdio.h>
#include <string.h>
#define MAX(a , b) ((a) > (b)) ? (a) : (b)
#define MIN(a , b) ((a) < (b)) ? (a) : (b)
typedef struct big{
    int n[1000];
    int len;
} BI;

void StoI(char *in, BI *out)
{
	int len = strlen(in), i;
	const int a[4] = {1, 10, 100, 1000};
	for(i = 0; i < 1000; i++)
	    out -> n[i] = 0;
	for(i = len - 1; i >= 0; i--)
		out -> n[(len - 1 - i) >> 2] += (in[i] - '0') * a[(len - 1 - i) % 4];
	out -> len = (len - 1) >> 2;
}
void ItoS(BI *in, char *out)
{
	int len = in -> len, i, j = 0, k, f = 1;
	int const a[4] = {1000, 100, 10, 1};
	for(i = 0; i <= len; i++) if(in -> n[i] != 0) f = 0;
	if(f) {out[0] = '0'; out[1] = '\0'; return;}
	for(i = len; i >= 0; i--)
	{
		k = 0;
		while(k < 4)
		{
			out[j] = (in -> n[i]) / a[j % 4] + '0';
			in -> n[i] %= a[j % 4];
			j++; k++;
		}
	}
	out[j] = '\0';
	for(i = 0; out[i] == '0'; i++);
	for(k = i; k <= j; k++)
		out[k - i] = out[k];
}
void Add(BI *a, BI b)
{
	int max = MAX(a->len, b.len), i, j;
	for(i = 0; i <= max; i++)
	{
	    a->n[i] += b.n[i];
		a->n[i+1] += a->n[i] / 10000;
		a->n[i] = a->n[i] % 10000;
	}
	if(a->n[i] == 0) a->len = i - 1;
	else a->len = i;
}
void Sub(BI *a, BI b)
{
    int min = MIN(a->len, b.len), i, j;
    for(i = 0; i <= min; i++)
    {
		a -> n[i] -= b.n[i];
		if(a -> n[i] < 0){a -> n[i + 1]--; a -> n[i] += 10000;}
	}
}
int main()
{
	
	return 0;
}


