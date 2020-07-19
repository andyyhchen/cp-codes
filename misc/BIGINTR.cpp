#include <iostream>
#define Max 1000
#define max(a , b) (a) > (b) ? (a) : (b)
#define min(a , b) (a) < (b) ? (a) : (b)

using namespace std;

typedef struct bigint{
	int len;
	int n[Max];
} BIG;

void CtoBIG(char *in, BIG &out)
{
	const int d[4] = {1, 10, 100, 1000};
	int len = strlen(in);
	for(int i = len - 1, k = len - 1; i >= 0; i--)
		out.n[(k - i) / 4] += (in[i] - '0') * d[(k - i) % 4];
	out.len = (len - 1) / 4;
}

void printBIG(BIG in)
{
	int tmp[Max];
	int len = in.len, k = 0, g = 0;
	const int d[4] = {1, 10, 100, 1000};
	for(int i = len + 1; i >= 0; i--)
	{
		for(int j = 3; j >= 0; j--)
		{
			tmp[k++] = in.n[i] / d[j];
			in.n[i] %= d[j];
		}
	}
	while(!tmp[g++]);
	for(int i = g - 1; i < k; i++)
	    printf("%d", tmp[i]);
	printf("\n");
}

void Add(BIG a, BIG b, BIG &out)
{
	int len = max(a.len, b.len);
	for(int i = 0; i <= len; i++)
	{
		out.n[i] = a.n[i] + b.n[i];
		out.n[i + 1] += out.n[i] / 10000;
		out.n[i] %= 10000;
	}
	out.len = len + 1;
}

void sub(BIG a, BIG b, BIG &c)
{
	int len = max(a.len, b.len);
	
	for(int i = 0; i <= len + 1; i++)
		c.n[i] = a.n[i] - b.n[i];

	for(int i = 0; i < Max - 1; i++)
	{
		if(c.n[i] < 0)
		{
			c.n[i] += 10000;
			c.n[i + 1] -= 1;
		}
	}
	c.len = len;
}



void mult(BIG a, BIG b, BIG &c)
{
	int lena = a.len, lenb = b.len;
	for(int i = 0; i <= lenb; i++)
	{
		for(int j = 0; j <= lena; j++)
		{
			c.n[j + i] += a.n[j] * b.n[i];
			c.n[j + i + 1] += c.n[j + i] / 10000;
			c.n[j + i] %= 10000;
		}
	}
	c.len = lena + lenb + 2;

}


int main()
{
	char a[Max], b[Max], c[Max];
	BIG f, d, e;
	while(gets(a))
	{
		gets(b);
        memset(f.n, 0, sizeof(f.n));
        memset(d.n, 0, sizeof(d.n));
        memset(e.n, 0, sizeof(e.n));
		CtoBIG(a, f);
		CtoBIG(b, d);
		mult(f, d, e);
		printBIG(e);
	}

	system("pause");
	return 0;
}
