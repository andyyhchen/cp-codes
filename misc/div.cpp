#include <iostream>
#define N 100

using namespace std;

typedef struct bignum{
	int len;
	char digit[N];
} bignum;

void bignum_ini(bignum &a)
{
	a.len = 0;
	memset(a.digit, 0, sizeof(digit));
}

bignum operator*(const bignum a, const int b)
{
	int lena = a.len;
	bignum tmp; bignum_ini(tmp);
	for(int i = 0; i < lena; i++)
	{
		tmp.digit[i] = a.digit[i] * b;
		tmp.digit[i+1] += tmp.digit[i] / 10;
		tmp.digit[i] %= 10;
	}
	int t_len = lena+ 10;
	while(tmp.digit[t_len] == 0) t_len--;
	if(t_len < 0)t_len = 0;
	tmp.len = t_len + 1;
	return tmp;
}

bignum operator-(const bignum a, const bignum b)
{
	int max_len = a.len;
	bignum tmp; bignum_ini(tmp);
	for(int i = 0; i < max_len; i++)
	{
		tmp.digit[i] += a.digit[i] - b.digit[i];
		if(tmp.digit[i] < 0)
		{
			tmp.digit[i+1]--;
			tmp.digit[i]+=10;
		}
	}
	int t_len = max_len + 10;
	while(tmp.digit[t_len] == 0) t_len--;
	tmp.len = t_len + 1;
	return tmp;
}

bool operator<(const bignum a, const bignum b)
{
	int lena = a.len, lenb = b.len;
	if(lena < lenb) return true;
	else if(lena > lenb) return false;
	else
	{
		for(int i = 0; i < lena; i++)
			if(a.digit[i]>b.digit[i]) return false;
	}
	return true;
}

bignum mult10(int pow, bignum a)
{
	int lena = a.len;
	bignum tmp; bignum_ini(tmp);
	for(int i = 0; i < lena; i++)
		tmp.digit[i + pow] = a.digit[i];
	tmp.len = lena + pow;
	return tmp;
}

bignum operator/(const bignum a, const bignum b)
{
    bignum tmp; bignum_ini(tmp);
    int lena = a.len, lenb = b.len;
    int sub = lena - lenb ;
    for(int i = sub; i >= 0; i--)
    {
		for(int j = 0; j < 10; j++)
		{
			if(a < mult10(i, b)*j)
			{
				a = a - mult10(i, b)*(j-1);
				tmp.digit[i] = j-1;
				break;
			}
		}
	}
    tmp.len = sub + 1;
    return tmp;
}

int main()
{

	system("pause");
	return 0;
}
