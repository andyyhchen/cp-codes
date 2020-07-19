#include <iostream>
#define Max 1010

using namespace std;

int main()
{
	char P[Max], Q[Max];
	while(gets(P)&&gets(Q))
	{
		int lenQ = strlen(Q), lenP = strlen(P), i, f = 1, max = -1;
		for(i = 0; i < min(lenQ, lenP); i++)
		{
			f = 1;
			for(int j = 0; j <= i; j++)
			{
				if(P[j]!=Q[lenQ - i - 1 + j])
				{
					f = 0;
					break;
				}
			}
			if(f && max < i) max = i;
		}
		printf("%d\n",max+1);
	}
	return 0;
}
