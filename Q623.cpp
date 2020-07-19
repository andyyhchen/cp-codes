#include <iostream>
#define Max 3000

using namespace std;

typedef struct bignumber{
	int len;
	char digit[Max];
} bignum;

bignum int2bignum(int n)
{
	bignum a = {0,{0}};
	int i = 0;
	if(!n) i++;
	while(n)
	{
  		a.digit[i++] = n % 10;
  		n /= 10;
	}
	a.len = i - 1;
	return a;
}

bignum operator*(bignum a, bignum b)    // a*b
{
	bignum ans = {0,{0}};
	int lena = a.len, lenb = b.len;
	for(int i = 0; i <= lena; i++)
	{
		for(int j = 0; j <= lenb; j++)
		{
			ans.digit[j + i] += b.digit[j] * a.digit[i];
			ans.digit[j + i + 1] += ans.digit[j + i] / 10;
			ans.digit[j + i] %= 10;
		}
	}
	int len = lena + lenb + 10;
	while(!ans.digit[len--]);
	ans.len = len + 1;
	return ans;
}

bignum table[1010];

int main()
{
	bignum tmp;
	for(int i = 0; i < 1010; i++)table[i] = int2bignum(i);
	int n;
	while(~scanf(" %d", &n))
	{
		if(!n) printf("1\n");
		else
		{
			tmp = table[n];
			for(int i = n - 1; i >= 1; i--) tmp = table[i] * tmp;
			for(int i = tmp.len; i >= 0; i--) printf("%d",tmp.digit[i]);
			printf("\n");
		}
	}
	return 0;
}
