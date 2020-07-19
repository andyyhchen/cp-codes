#include <iostream>
#define Max 100;
#define MAX(a , b) (a) > (b) ? (a) : (b)

using namespace std;

typedef struct big{
	int len;
	int n[Max];
} Bi;

void ini(BI *in)
{
	memset(in->n, 0, sizeof(in->n));
	in->len = 0;
}

void CtoB(char in[Max*4], Bi *out)
{
	ini(out);
	
}

int main()
{

}
